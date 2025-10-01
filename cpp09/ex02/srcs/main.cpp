#include <iostream>
#include <iomanip>
#include "PmergeMe.hpp"
#include "VectorPmergeMe.hpp"
#include "DequePmergeMe.hpp"

void print_values_line(const std::list<element>& elems) {
	std::list<element>::const_iterator it = elems.begin();
	std::cout << "Before: ";
	for (; it != elems.end(); ) {
		std::cout << it->value;
		++it;
		if (it != elems.end()) std::cout << ' ';
	}
	std::cout << std::endl;
}

void print_values_line(const std::vector<element>& elems) {
	std::vector<element>::const_iterator it = elems.begin();
	std::cout << "After: ";
	for (; it != elems.end(); ) {
		std::cout << it->value;
		++it;
		if (it != elems.end()) std::cout << ' ';
	}
	std::cout << std::endl;
}

void print_values_line(const std::deque<element>& elems) {
	std::deque<element>::const_iterator it = elems.begin();
	std::cout << "After: ";
	for (; it != elems.end(); ) {
		std::cout << it->value;
		++it;
		if (it != elems.end()) std::cout << ' ';
	}
	std::cout << std::endl;
}

static double to_microseconds(std::clock_t ticks) {
	return 1e6 * static_cast<double>(ticks) / static_cast<double>(CLOCKS_PER_SEC);
}

int main(int argc, char **argv) {
	try {
		//引数の初期化
		const std::list<element> arg_list = initArgument(argc, argv);
		print_values_line(arg_list);
		//vector
		vectorPmergeMe vimpl(arg_list);
		vimpl.pmergeMe_sort();
		const double vec_us = to_microseconds(vimpl.getProcessTime());
		// deque
		dequePmergeMe dimpl(arg_list);
		dimpl.pmergeMe_sort();
		const double deq_us = to_microseconds(dimpl.getProcessTime());
		const std::size_t n = vimpl.getVector().size();

		//vector
		std::cout << "vector sort" << std::endl;
		std::cout << "Time to process a range of " << n
			<< " elements with std::vector : "
			<< std::fixed << std::setprecision(5) << vec_us << " us" << std::endl;
		print_values_line(vimpl.getVector());
		std::cout << "vector compare count: " << vimpl.getCounter() << std::endl;

		//deque
		std::cout << "deque sort" << std::endl;
		std::cout << "Time to process a range of " << n
			<< " elements with std::deque  : "
			<< std::fixed << std::setprecision(5) << deq_us << " us" << std::endl;
		print_values_line(dimpl.getDeque());
		std::cout << "deque compare count: " << dimpl.getCounter() << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}
