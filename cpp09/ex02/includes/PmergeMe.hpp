#ifndef PMERGEME_HPP
# define PMERGEME_HPP
# include <iostream>
# include <list>
# include <ctime>
# include <vector>
# include <deque>
# include <cstddef>
#include "element.hpp"


class pmergeMe {
protected:
	std::clock_t _start;
	std::clock_t _end;
	size_t _counter;
public:
	virtual ~pmergeMe() = 0;
	virtual void pmergeMe_sort() = 0;
	void setStartTime();
	void setEndTime();
	size_t getCounter() const;
	std::clock_t getStartTime();
	std::clock_t getEndTime();
	std::clock_t getProcessTime();
};


int strToInt(std::string input);
bool isValidNumber(std::string input);
const std::list<element> initArgument(int argument_c, const char* const* argument);
std::time_t getCurrentTime();
void printVector(const std::vector<element>& vec);
void printDeque(const std::deque<element>& deq);

#endif
