#ifndef DEQUE_PMERGEME_HPP
# define DEQUE_PMERGEME_HPP

#include "PmergeMe.hpp"
#include "element.hpp"
#include <deque>
#include <list>
#include <cstddef>

class dequePmergeMe : public pmergeMe {
private:
	std::deque<element> _deque;
	dequePmergeMe();
public:
	dequePmergeMe(const std::list<element>& arg_list);
	~dequePmergeMe();
	dequePmergeMe(const dequePmergeMe& other);
	dequePmergeMe &operator=(const dequePmergeMe& other);
	std::deque<element> getDeque() const;
	bool compValue(const element& a, const element& b);
	void pmergeMe_sort();
	void divIntoLargeAndSmall(std::deque<element>& original, std::deque<element>& large, std::deque<element>& small);
	void sorting(std::deque<element>& original);
	void restore_large_index(std::deque<element>& original, std::deque<element>& large);
	int search_pair_id(std::deque<element>& original, size_t index);
	void insert_smallest_el(std::deque<element>& large, std::deque<element>& small);
	void arrange_to_large(std::deque<element>& large, std::deque<element>& small);
	void arrange_to_jacobsthal(std::deque<element>& small);
	std::vector<size_t> make_jacobsthal_order(size_t n);
	void insertion(std::deque<element>& large, std::deque<element>& small);
	std::deque<element>::iterator binary_search(element& el, std::deque<element>::iterator head, std::deque<element>::iterator tail);
	size_t sum_vec_val(std::vector<size_t> group);
	std::deque<element>::iterator find_last_with_pair_id(std::deque<element>& large, element& pair);
	element find_el_with_pair_id(std::deque<element>& small, int pair_id);
};

#endif
