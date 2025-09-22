#ifndef LIST_PMERGE_ME
# define LIST_PMERGE_ME

#include "PmergeMe.hpp" 

class dequePmergeMe : public pmergeMe {
private:
	std::deque<element> _deque;
public:
	dequePmergeMe();
	dequePmergeMe(const std::list<element>& arg_list);
	~dequePmergeMe();
	dequePmergeMe(const dequePmergeMe& other);
	dequePmergeMe &operator=(const dequePmergeMe& other);
	void pmergeMe_sort();
	void divIntoLargeAndSmall(std::deque<element>& original, std::deque<element>& large, std::deque<element>& small);
	void merge_part(std::deque<element>& original);
	void sorting(std::deque<element>& original);
	void inserting(std::deque<element>& original, std::deque<element>& large, std::deque<element>& small);
	static bool compValue(const element& a, const element& b);
	std::deque<element> getDeque() const;
	void groupJacobsthal(std::deque<element>& small, std::deque<element>& large);
	std::deque<size_t> make_jacobsthal_order(size_t n);
	void build_pairid_table_by_index(const std::deque<element>& vec, std::deque<int>& pid_by_index);
	void restore_pairid_from_index_table(std::deque<element>& vec, const std::deque<int>& pid_by_index);
};

#endif
