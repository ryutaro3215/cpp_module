#ifndef VECTOR_PMERGEME_HPP
# define VECTOR_PMERGEME_HPP

#include "PmergeMe.hpp"
#include "element.hpp"
#include <vector>

class vectorPmergeMe : public pmergeMe {
private:
	std::vector <element> _vector;
	vectorPmergeMe();
public:
	vectorPmergeMe(const std::list<element>& arg_list);
	~vectorPmergeMe();
	vectorPmergeMe(const vectorPmergeMe& other);
	vectorPmergeMe &operator=(const vectorPmergeMe& other);
	std::vector<element> getVector() const;
	bool compValue(const element& a, const element& b);
	void pmergeMe_sort();
	void divIntoLargeAndSmall(std::vector<element>& original, std::vector<element>& large, std::vector<element>& small);
	void sorting(std::vector<element>& original);
	void restore_large_index(std::vector<element>& original, std::vector<element>& large);
	int search_pair_id(std::vector<element>& original, int value);
	void insert_smallest_el(std::vector<element>& large, std::vector<element>& small);
	void arrange_to_jacobsthal(std::vector<element>& small);
	std::vector<size_t> make_jacobsthal_order(size_t n);
	void insertion(std::vector<element>& large, std::vector<element>& small);
	std::vector<element>::iterator binary_search(element& el, std::vector<element>::iterator head, std::vector<element>::iterator tail);
	size_t sum_vec_val(std::vector<size_t> group);
	std::vector<element>::iterator find_last_with_pair_id(std::vector<element>& large, int pair_id);
};



#endif
