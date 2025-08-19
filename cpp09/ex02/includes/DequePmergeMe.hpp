#ifndef LIST_PMERGE_ME
# define LIST_PMERGE_ME

#include "PmergeMe.hpp" 

class listPmergeMe : public pmergeMe {
private:
	std::list<int> _list;
public:
	listPmergeMe();
	~listPmergeMe();
	listPmergeMe(const listPmergeMe& other);
	listPmergeMe &operator=(const listPmergeMe& other);
	void pmergeMe_sort();
};

#endif
