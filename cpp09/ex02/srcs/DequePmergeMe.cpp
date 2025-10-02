#include "DequePmergeMe.hpp"
#include <algorithm> // std::min
#include <cstddef>   // size_t

dequePmergeMe::dequePmergeMe() {}
dequePmergeMe::~dequePmergeMe() {}

dequePmergeMe::dequePmergeMe(const std::list<element>& arg_list) {
	for (std::list<element>::const_iterator it = arg_list.begin(); it != arg_list.end(); ++it)
		_deque.push_back(*it);
	_counter = 0; 
}

dequePmergeMe::dequePmergeMe(const dequePmergeMe& other) {
	for (std::deque<element>::const_iterator it = other._deque.begin(); it != other._deque.end(); ++it)
		_deque.push_back(*it);
}

dequePmergeMe& dequePmergeMe::operator=(const dequePmergeMe& other) {
	if (this == &other) return *this;
	_deque = other._deque;
	return *this;
}

std::deque<element> dequePmergeMe::getDeque() const {
	return _deque;
}

void dequePmergeMe::pmergeMe_sort() {
	setStartTime();
	sorting(_deque);
	setEndTime();
}

void dequePmergeMe::sorting(std::deque<element>& original) {
	if (original.size() <= 1) return;
	std::deque<element> large, small;
	divIntoLargeAndSmall(original, large, small);
	sorting(large);
	restore_large_index(original, large);
	insert_smallest_el(large, small);
	arrange_to_jacobsthal(small);
	insertion(large, small);
	original.swap(large);
}

void dequePmergeMe::divIntoLargeAndSmall(std::deque<element>& original, std::deque<element>& large, std::deque<element>& small)
{
	int pair_num = 0;
	size_t i = 0;
	for (; i + 1 < original.size(); i += 2) {
		original[i].pair_id     = pair_num;
		original[i + 1].pair_id = pair_num;
		int left  = original[i].value;
		int right = original[i + 1].value;
		if (left < right) {
			small.push_back(original[i]);
			large.push_back(original[i + 1]);
		} else {
			small.push_back(original[i + 1]);
			large.push_back(original[i]);
		}
		_counter++; // 比較カウント
		pair_num++;
	}
	if (original.size() % 2 == 1) {
		element tail = original.back();
		tail.pair_id = -1;
		small.push_back(tail);
	}
}

void dequePmergeMe::restore_large_index(std::deque<element>& original, std::deque<element>& large) {
	for (std::deque<element>::iterator it = large.begin(); it != large.end(); ++it) {
		it->pair_id = search_pair_id(original, it->value);
	}
}

int dequePmergeMe::search_pair_id(std::deque<element>& original, int value) {
	for (std::deque<element>::const_iterator it = original.begin(); it != original.end(); ++it) {
		if (it->value == value) return it->pair_id;
	}
	return -2; // 想定外
}

void dequePmergeMe::insert_smallest_el(std::deque<element>& large, std::deque<element>& small) {
	if (large.empty()) return;

	const int head_pid = large.front().pair_id;
	if (head_pid < 0) return; 

	for (std::deque<element>::iterator sit = small.begin(); sit != small.end(); ++sit) {
		if (sit->pair_id == head_pid) {
			large.push_front(*sit);
			small.erase(sit);
			break;
		}
	}
}

void dequePmergeMe::arrange_to_jacobsthal(std::deque<element>& small) {
	const size_t n = small.size();
	if (n <= 1) return;

	std::vector<size_t> ord = make_jacobsthal_order(n);
	std::deque<element> arranged;
	arranged.resize(n);
	for (size_t k = 0; k < ord.size(); ++k) {
		arranged[k] = small[ord[k]];
	}
	small.swap(arranged);
}

std::vector<size_t> dequePmergeMe::make_jacobsthal_order(size_t n) {
	std::vector<size_t> order;
	if (n == 0) return order;
	order.reserve(n);

	std::vector<size_t> groups;
	size_t used = 0;
	size_t g1 = 2, g2 = 2;
	size_t next_pow2 = 8;

	groups.push_back(std::min(g1, n - used)); used += std::min(g1, n - (used));
	if (used < n) { groups.push_back(std::min(g2, n - used)); used += std::min(g2, n - used); }

	size_t gprev = g2;
	while (used < n) {
		size_t gcur = next_pow2 - gprev; 
		size_t take = std::min(gcur, n - used);
		groups.push_back(take);
		used += take;
		gprev = gcur;
		next_pow2 <<= 1;
	}

	size_t base = 0;
	for (size_t gi = 0; gi < groups.size(); ++gi) {
		size_t len = groups[gi];
		if (len == 0) break;
		size_t start = base;
		size_t end   = base + len;
		size_t i = end;
		while (i-- > start) order.push_back(i);
		base += len;
	}
	return order;
}

void dequePmergeMe::insertion(std::deque<element>& large, std::deque<element>& small) {
	for (std::deque<element>::iterator it = small.begin(); it != small.end(); ++it) {
		std::deque<element>::iterator upperIt = find_last_with_pair_id(large, it->pair_id);
		if (upperIt == large.end()) {
			upperIt = large.end();
		}
		std::deque<element>::iterator pos = binary_search(*it, large.begin(), upperIt);
		large.insert(pos, *it);
	}
}

std::deque<element>::iterator dequePmergeMe::find_last_with_pair_id(std::deque<element>& large, int pair_id) {
	for (std::deque<element>::iterator it = large.end(); it != large.begin();) {
		--it;
		if (it->pair_id == pair_id)
			return it;
	}
	return large.end();
}

std::deque<element>::iterator
dequePmergeMe::binary_search(element& el, std::deque<element>::iterator head, std::deque<element>::iterator tail)
{
	if (head == tail) return head;
	std::deque<element>::iterator mid = head + (tail - head) / 2;
	_counter++;
	if (mid->value < el.value) {
		return binary_search(el, mid + 1, tail);
	} else {
		return binary_search(el, head, mid);
	}
}

size_t dequePmergeMe::sum_vec_val(std::vector<size_t> group) {
	size_t s = 0;
	for (std::vector<size_t>::const_iterator it = group.begin(); it != group.end(); ++it) s += *it;
	return s;
}
