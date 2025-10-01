#include <sstream>
#include <climits>
#include "PmergeMe.hpp"


pmergeMe::~pmergeMe() {}

void pmergeMe::setStartTime() {
	_start = std::clock();
}

void pmergeMe::setEndTime() {
	_end = std::clock();
}

std::clock_t pmergeMe::getStartTime() {
	return _start;
}

std::clock_t pmergeMe::getEndTime() {
	return _end;
}

std::clock_t pmergeMe::getProcessTime() {
	return getEndTime() - getStartTime();
}

bool isValidNumber(std::string input) {
	for (size_t i = 0; i < input.length(); i++) {
		if (!std::isdigit(input[i]))
			return false;
	}
	return true;
}

int strToInt(std::string input) {
	std::istringstream iss(input);
	long result;

	if (!(iss >> result) && !iss.eof())
		throw std::runtime_error("Invalid number");
	if (result > INT_MAX)
		throw std::runtime_error("Integer Overflow");
	return result;
}

const std::list<element> initArgument(int argument_c, const char* const* argument) {
	std::list<element> init_list;
	for (int i = 1; i < argument_c; i++) {
		if (!isValidNumber(argument[i]))
			throw std::runtime_error("Invalid Input");
		try {
			element elem;
			elem.index = i - 1;
			elem.value = strToInt(argument[i]);
			elem.pair_id = -1;
			init_list.push_back(elem);
		} catch (std::exception &e) {
			throw std::runtime_error(e.what());
		}
	}
	return init_list;
}

std::time_t getCurrentTime() {
	std::time_t now = std::time(NULL);
	return now;
}

void printVector(const std::vector<element>& vec) {
	for (std::vector<element>::const_iterator it = vec.begin(); it != vec.end(); it++)
		std::cout << "vec[" << it->index << "]: " << it->value << "pair_id: " << it->pair_id <<  std::endl;
}

void printDeque(const std::deque<element>& deq) {
	for (std::deque<element>::const_iterator it = deq.begin(); it != deq.end(); it++)
		std::cout << "deq[" << it->index << "]: " << it->value << "pair_id: " << it->pair_id <<  std::endl;
}

size_t pmergeMe::getCounter() const {
	return _counter;
}
