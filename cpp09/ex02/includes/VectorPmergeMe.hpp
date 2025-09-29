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
	void pmergeMe_sort();
	void divIntoLargeAndSmall(std::vector<element>& original, std::vector<element>& large, std::vector<element>& small);
	void merge_part(std::vector<element>& original);
	void sorting(std::vector<element>& original);
	void inserting(std::vector<element>& original, std::vector<element>& large, std::vector<element>& small);
	static bool compValue(const element& a, const element& b);
	std::vector<element> getVector() const;
	void groupJacobsthal(std::vector<element>& small, std::vector<element>& large);
	std::vector<size_t> make_jacobsthal_order(size_t n);
	void build_pairid_table_by_index(const std::vector<element>& vec, std::vector<int>& pid_by_index);
	void restore_pairid_from_index_table(std::vector<element>& vec, const std::vector<int>& pid_by_index);
};



#endif
