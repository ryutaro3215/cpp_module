#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <list>

class pmergeMe {
public:
	virtual ~pmergeMe() = 0;
	virtual void pmerge_sort() = 0;
};

class vectorPmergeMe : public pmergeMe {
private:
	std::vector <int> _vector;
public:
	vectorPmergeMe();
	~vectorPmergeMe();
	vectorPmergeMe(const vectorPmergeMe& other);
	vectorPmergeMe &operator=(const vectorPmergeMe& other);
	void pmergeMe_sort();
};

class listPmergeMe : public pmergeMe {
private:
	std::list<int> _list;
public:
	listPmergeMe();
	~listPmergeMe();
	listPmergeMe(const listPmergeMe& other);
	listPmergeMe &operator=(const listPmergeMe& other);
	void pmerge_sort();
};

int strToInt(std::string input);

#endif
