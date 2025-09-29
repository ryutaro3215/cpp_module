#include "DequePmergeMe.hpp"
#include <algorithm>

dequePmergeMe::dequePmergeMe() {}

dequePmergeMe::~dequePmergeMe() {}

dequePmergeMe::dequePmergeMe(const std::list<element>& arg_list) {
	for (std::list<element>::const_iterator it = arg_list.begin(); it != arg_list.end(); it++)
		_deque.push_back(*it);
}

dequePmergeMe::dequePmergeMe(const dequePmergeMe& other) {
	for (std::deque<element>::const_iterator it = other._deque.begin(); it != other._deque.end(); it++)
		this->_deque.push_back(*it);
}

dequePmergeMe &dequePmergeMe::operator=(const dequePmergeMe& other) {
	if (this == &other)
		return *this;
	_deque = other._deque;
	return *this;
}

std::deque<element> dequePmergeMe::getDeque() const {
	return _deque;
}

void dequePmergeMe::pmergeMe_sort() {
	//Starting Algorithm
	setStartTime();
	sorting(_deque);
	setEndTime();
}

void dequePmergeMe::sorting(std::deque<element>& original) {
	if (original.size() <= 1)
		return ;
	std::deque<element> large, small;
	divIntoLargeAndSmall(original, large, small);
	std::deque<int> pairid_by_index;
	build_pairid_table_by_index(large, pairid_by_index);
	sorting(large);
	restore_pairid_from_index_table(large, pairid_by_index);
	groupJacobsthal(small, large);
	inserting(original, large, small);
}

void dequePmergeMe::divIntoLargeAndSmall(std::deque<element>& original, std::deque<element>& large, std::deque<element>& small) {
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

void dequePmergeMe::groupJacobsthal(std::deque<element>& small, std::deque<element>& large) {
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

	std::deque<element> small_by_id(max_id + 1);
	std::deque<char> has_small(max_id + 1, 0);

	for (size_t i = 0; i < small.size(); ++i) {
		const int pid = small[i].pair_id;
		if (pid >= 0 && pid <= max_id) {
			small_by_id[pid] = small[i];
			has_small[pid] = 1;
		}
	}
	std::deque<element> small_in_chain_order;

	std::deque<element>::const_iterator lit = large.begin();
	for (; lit != large.end(); ++lit) {
		const int pid = lit->pair_id;
		if (pid >= 0 && pid <= max_id && has_small[pid]) 
			small_in_chain_order.push_back(small_by_id[pid]);
	}

	std::deque<size_t> ord = dequePmergeMe::make_jacobsthal_order(small_in_chain_order.size());
	std::deque<element> jacob_small;
	for (size_t i = 0; i < ord.size(); ++i) {
		jacob_small.push_back(small_in_chain_order[ord[i]]);
	}

	small.swap(jacob_small);
}

void dequePmergeMe::inserting(std::deque<element>& original, std::deque<element>& large, std::deque<element>& small) {
	original = large;
	for (std::deque<element>::const_iterator sit = small.begin(); sit != small.end(); ++sit) {
		const int up_pair = sit->pair_id;
		std::deque<element>::iterator upperIt = original.begin();
		for (; upperIt != original.end(); ++upperIt) {
			if (upperIt->pair_id == up_pair) break;
		}
		if (upperIt == original.end()) upperIt = original.end();
		std::deque<element>::iterator pos =
			std::lower_bound(original.begin(), upperIt, *sit, &dequePmergeMe::compValue);
		original.insert(pos, *sit);
	}
}

bool dequePmergeMe::compValue(const element& a, const element& b) {
	return a.value < b.value;
}

std::deque<size_t> dequePmergeMe::make_jacobsthal_order(size_t n) {
	std::deque<size_t> J;
	if (n == 0) {
		return std::deque<size_t>();
	}

	J.push_back(1);
	while (J.back() < n) {
		if (J.size() == 1)
			J.push_back(3);
		else
			J.push_back(J[J.size() - 1] + 2 * J[J.size() - 2]);
	}

	std::deque<size_t> order;
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
void dequePmergeMe::build_pairid_table_by_index(const std::deque<element>& vec, std::deque<int>& pid_by_index) {
	size_t i;
	for (i = 0; i < vec.size(); ++i) {
		const size_t idx = static_cast<size_t>(vec[i].index);
		if (idx >= pid_by_index.size())
			pid_by_index.resize(idx + 1, -2); // -2 は未設定の印
		pid_by_index[idx] = vec[i].pair_id;
	}
}

void dequePmergeMe::restore_pairid_from_index_table(std::deque<element>& vec, const std::deque<int>& pid_by_index) {
	size_t i;
	for (i = 0; i < vec.size(); ++i) {
		const size_t idx = static_cast<size_t>(vec[i].index);
		if (idx < pid_by_index.size() && pid_by_index[idx] != -2) {
			vec[i].pair_id = pid_by_index[idx];
		}
	}
}



