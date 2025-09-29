#include "VectorPmergeMe.hpp"
#include <algorithm>

vectorPmergeMe::vectorPmergeMe() {}

vectorPmergeMe::~vectorPmergeMe() {}

vectorPmergeMe::vectorPmergeMe(const std::list<element>& arg_list) {
	for (std::list<element>::const_iterator it = arg_list.begin(); it != arg_list.end(); it++)
		_vector.push_back(*it);
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
	divIntoLargeAndSmall(original, large, small);
	std::vector<int> pairid_by_index;
	build_pairid_table_by_index(large, pairid_by_index);
	sorting(large);
	restore_pairid_from_index_table(large, pairid_by_index);
	groupJacobsthal(small, large);
	inserting(original, large, small);
}

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
		pair_num++;
	}
	if (original.size() % 2 == 1) {
		element tail = original.back();
		tail.pair_id = -1;
		large.push_back(tail);
	}
}

void vectorPmergeMe::groupJacobsthal(std::vector<element>& small, std::vector<element>& large) {
	if (small.empty())
		return ;

	size_t i = 0;
	int max_id = -1;
	for (i = 0; i < small.size(); ++i) {
		if (small[i].pair_id > max_id)
			max_id = small[i].pair_id;
	}
	if (max_id < 0) {
		small.clear();
		return ;
	}

	std::vector<element> small_by_id(max_id + 1);
	std::vector<char> has_small(max_id + 1, 0);

	for (size_t i = 0; i < small.size(); ++i) {
		const int pid = small[i].pair_id;
		if (pid >= 0 && pid <= max_id) {
			small_by_id[pid] = small[i];
			has_small[pid] = 1;
		}
	}
	std::vector<element> small_in_chain_order;
	small_in_chain_order.reserve(small.size());

	std::vector<element>::const_iterator lit = large.begin();
	for (; lit != large.end(); ++lit) {
		const int pid = lit->pair_id;
		if (pid >= 0 && pid <= max_id && has_small[pid]) 
			small_in_chain_order.push_back(small_by_id[pid]);
	}

	std::vector<size_t> ord = vectorPmergeMe::make_jacobsthal_order(small_in_chain_order.size());
	std::vector<element> jacob_small;
	jacob_small.reserve(small_in_chain_order.size());
	for (size_t i = 0; i < ord.size(); ++i) {
		jacob_small.push_back(small_in_chain_order[ord[i]]);
	}

	small.swap(jacob_small);
}

void vectorPmergeMe::inserting(std::vector<element>& original, std::vector<element>& large, std::vector<element>& small) {
	original = large;
	original.reserve(large.size() + small.size());
	for (std::vector<element>::const_iterator sit = small.begin(); sit != small.end(); ++sit) {
		const int up_pair = sit->pair_id;
		std::vector<element>::iterator upperIt = original.begin();
		for (; upperIt != original.end(); ++upperIt) {
			if (upperIt->pair_id == up_pair) break;
		}
		if (upperIt == original.end()) upperIt = original.end();
		std::vector<element>::iterator pos =
			std::lower_bound(original.begin(), upperIt, *sit, &vectorPmergeMe::compValue);
		original.insert(pos, *sit);
	}
}

bool vectorPmergeMe::compValue(const element& a, const element& b) {
	return a.value < b.value;
}

std::vector<size_t> vectorPmergeMe::make_jacobsthal_order(size_t n) {
	std::vector<size_t> J;
	if (n == 0) {
		return std::vector<size_t>();
	}

	J.push_back(1);
	while (J.back() < n) {
		if (J.size() == 1)
			J.push_back(3);
		else
			J.push_back(J[J.size() - 1] + 2 * J[J.size() - 2]);
	}

	std::vector<size_t> order;
	order.push_back(0);
	size_t prev = 1;
	for (size_t k = 0; prev < n; ++k) {
		size_t cur = (J[k] < n) ? J[k] : n;
		if (cur <= prev) {
			prev = cur;
			continue;
		}
		size_t i = cur;
		while (i-- > prev) {
			order.push_back(i);
		}
		prev = cur;
	}
	return order;
}
void vectorPmergeMe::build_pairid_table_by_index(const std::vector<element>& vec, std::vector<int>& pid_by_index) {
	size_t i;
	for (i = 0; i < vec.size(); ++i) {
		const size_t idx = static_cast<size_t>(vec[i].index);
		if (idx >= pid_by_index.size())
			pid_by_index.resize(idx + 1, -2); // -2 は未設定の印
		pid_by_index[idx] = vec[i].pair_id;
	}
}

void vectorPmergeMe::restore_pairid_from_index_table(std::vector<element>& vec, const std::vector<int>& pid_by_index) {
	size_t i;
	for (i = 0; i < vec.size(); ++i) {
		const size_t idx = static_cast<size_t>(vec[i].index);
		if (idx < pid_by_index.size() && pid_by_index[idx] != -2) {
			vec[i].pair_id = pid_by_index[idx];
		}
	}
}



