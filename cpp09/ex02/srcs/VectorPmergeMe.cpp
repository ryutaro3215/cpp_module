#include "VectorPmergeMe.hpp"
#include "PmergeMe.hpp"
#include <algorithm>


vectorPmergeMe::vectorPmergeMe() {}

vectorPmergeMe::~vectorPmergeMe() {}

vectorPmergeMe::vectorPmergeMe(const std::list<element>& arg_list) {
	for (std::list<element>::const_iterator it = arg_list.begin(); it != arg_list.end(); it++)
		_vector.push_back(*it);
	_counter = 0;
}

vectorPmergeMe::vectorPmergeMe(const vectorPmergeMe& other) {
	for (std::vector<element>::const_iterator it = other._vector.begin(); it != other._vector.end(); it++)
		this->_vector.push_back(*it);
}

vectorPmergeMe &vectorPmergeMe::operator=(const vectorPmergeMe& other) {
	if (this == &other)
		return *this;
	_vector = other._vector;
	return *this;
}

std::vector<element> vectorPmergeMe::getVector() const {
	return _vector;
}

void vectorPmergeMe::pmergeMe_sort() {
	//Starting Algorithm
	setStartTime();
	sorting(_vector);
	setEndTime();
}

void vectorPmergeMe::sorting(std::vector<element>& original) {
	if (original.size() <= 1)
		return ;
	std::vector<element> large, small;
	//元のベクターをlarge, smallに先頭からペアごとに比較、分割する。
	divIntoLargeAndSmall(original, large, small);
	//largeに対して再帰的にsortingを実施
	sorting(large);
	//再帰から帰ってきたら、元の配列のpair_idを復元する。
	restore_large_index(original, large);
	//largeの先頭とペアのsmallの要素を探して、比較0回でlargeの先頭に入れ込む
	insert_smallest_el(large, small);
	//ソートずみlargeに対応したpair_idの順番にsmallを並べ替える
	arrange_to_large(large, small);
	//smallをjacobsthal数列の順序に並べ替える
	arrange_to_jacobsthal(small);
	//二部探索を実行する。smallの要素をlargeに入れる
	insertion(large, small);
	// std::cout << "small" << std::endl;
	// printVector(small);
	// std::cout << "large" << std::endl;
	// printVector(large);
	//完成したソート済みの要素たち(large)をoriginalに反映させる。
	//再帰しているのでこれをしないと結果が上の階層に反映されない
	original.swap(large);
}

//ソート前の配列を前から二つずつでペアにしてlarge, smallに分割する。これは再帰的に発生する
void vectorPmergeMe::divIntoLargeAndSmall(std::vector<element>& original, std::vector<element>& large, std::vector<element>& small) {
	int pair_num = 0;
	for (size_t i = 0; i + 1 < original.size(); i += 2) {
		original[i].pair_id = pair_num;
		original[i + 1].pair_id = pair_num;
		int left = original[i].value;
		int right = original[i + 1].value;
		if (left < right) {
			small.push_back(original[i]);
			large.push_back(original[i + 1]);
		} else {
			small.push_back(original[i + 1]);
			large.push_back(original[i]);
		}
		//比較回数のカウント
		_counter++;
		pair_num++;
	}
	if (original.size() % 2 == 1) {
		element tail = original.back();
		tail.pair_id = -1;
		small.push_back(tail);
	}
}

//再帰から帰ってきた時にここでlargeのpair_idをその階層でのpair_idに復元する
void vectorPmergeMe::restore_large_index(std::vector<element>& original, std::vector<element>& large) {
	for (std::vector<element>::iterator it = large.begin(); it != large.end(); it++) {
		it->pair_id = search_pair_id(original, it->index);
	}
}

//indexに対応したその階層でのpair_idを探してくる
int vectorPmergeMe::search_pair_id(std::vector<element>& original, size_t index) {
	for (std::vector<element>::const_iterator it = original.begin(); it != original.end(); it++) {
		if (it->index == index)
			return it->pair_id;
	}
	//可能性はほぼない
	return -2;
}

//largeの先頭要素に対応するsmallの要素をlargeの先頭に挿入する（比較回数ゼロ）
void vectorPmergeMe::insert_smallest_el(std::vector<element>& large, std::vector<element>& small) {
	if(large.empty())
		return;
	const int head_pid = large.front().pair_id;
	std::vector<element>::iterator sit = small.begin();
	for (; sit != small.end(); ++sit) {
		if (sit->pair_id == head_pid) {
			large.insert(large.begin(), *sit);
			small.erase(sit);
			break;
		}
	}
	return ;
}

//largeのpair_idと同じ順番にsmallを並べ替える
void vectorPmergeMe::arrange_to_large(std::vector<element>& large, std::vector<element>& small) {
	std::vector<element> arranged_small;
	for (std::vector<element>::const_iterator it = large.begin() + 2; it < large.end(); ++it) {
		element pair_small = find_el_with_pair_id(small, it->pair_id);
		arranged_small.push_back(pair_small);
	}
	if (arranged_small.size() != small.size())
		arranged_small.push_back(*small.end());
	small.swap(arranged_small);
}

//同じpair_idを持つelementを見つける　
element vectorPmergeMe::find_el_with_pair_id(std::vector<element>& small, int pair_id) {
	for (std::vector<element>::iterator it = small.begin(); it < small.end(); ++it) {
		if (it->pair_id == pair_id)
			return *it;
	}
	element err;
	err.pair_id = -2;
	return err;
}

//smallの要素をjacobsthal_order順に並べ替える
//並べ替えればその順番のままlargeにインサートできる
//jacobsthal数を使うのは、それを使うことで二分探索の時の最悪比較回数を抑えられる。
//探索範囲を2^n - 1に抑えるため
void vectorPmergeMe::arrange_to_jacobsthal(std::vector<element>& small) {
	std::vector<size_t> jacobsthal = make_jacobsthal_order(small.size());
	std::vector<element> arranged_small;
	for (std::vector<size_t>::const_iterator it = jacobsthal.begin(); it < jacobsthal.end(); ++it) {
		arranged_small.push_back(small[*it]);
	}
	small.swap(arranged_small);
}

//jacobsthal orderを作る ([1, 0], [3, 2], [9, 8, 7, 6, 5, 4])
std::vector<size_t> vectorPmergeMe::make_jacobsthal_order(size_t n) {
	//jacobsthalを使ってsmallを先頭からグルーピングするときの一つのグループの要素の数を決める
	//groupは[2, 2, 6, 10...] -> 隣り合った要素の和が2の冪乗になるように。
	std::vector<size_t> group;
	std::vector<size_t> jacobstal_order;
	size_t g0 = 2;
	group.push_back(g0);
	size_t prev = g0;
	size_t exp = 2;
	while (true) {
		size_t now = exp *2 - prev;
		group.push_back(now);
		prev = now;
		exp *= 2;
		if (sum_vec_val(group) >= n)
			break ;
	}
	//作ったグループを元にして、挿入順序のindex列を作る
	size_t el_count = 0;
	for (size_t l = 0; l < group.size(); ++l) {
		size_t size = std::min(group[l], n - el_count);
		if (size== 0)
			break;
		size_t start = el_count;
		size_t end = el_count + size;
		size_t i = end - 1;
		while (true) {
			jacobstal_order.push_back(i);
			if (i == start)
				break;
			i--;
		}
		el_count += size;
		if (el_count == n)
			break;
	}
	return jacobstal_order;
}

//groupの数をたす
//要素数を超えたら止めるために使う
size_t vectorPmergeMe::sum_vec_val(std::vector<size_t> group) {
	size_t sum = 0;
	for (std::vector<size_t>::const_iterator it = group.begin(); it != group.end(); ++it)
		sum += *it;
	return sum;
}

void vectorPmergeMe::insertion(std::vector<element>& large, std::vector<element>& small) {
	for(std::vector<element>::iterator it = small.begin(); it < small.end(); ++it) {
		std::vector<element>::iterator upperIt = find_last_with_pair_id(large, *it);
		std::vector<element>::iterator pos = binary_search(*it, large.begin(), upperIt);
		large.insert(pos, *it);
	}
}
//挿入する要素の相方のiteratorを見つける
std::vector<element>::iterator vectorPmergeMe::find_last_with_pair_id(std::vector<element>& large,element& pair) {
	for (std::vector<element>::iterator it = large.end(); it != large.begin();) {
		--it;
		if (it->pair_id == pair.pair_id)
			return it;
	}
	return large.end();
}

//実際の二部探索
std::vector<element>::iterator vectorPmergeMe::binary_search(element& el, std::vector<element>::iterator head, std::vector<element>::iterator tail) {
	if (head == tail)
		return head;
	std::vector<element>::iterator mid = head + (tail - head) / 2;
	_counter++;
	if (mid->value < el.value) {
		return binary_search(el, mid + 1, tail);
	} else {
		return binary_search(el, head, mid);
	}
}

