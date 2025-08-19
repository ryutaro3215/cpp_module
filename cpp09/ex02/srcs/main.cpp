#include "PmergeMe.hpp"
#include "VectorPmergeMe.hpp"

int main(int argc, char **argv) {
	try {
		const std::list<element> arg_list = initArgument(argc, argv);
		vectorPmergeMe vector_list = vectorPmergeMe(arg_list);
		std::cout << "Befor" << std::endl;
		printVector(vector_list.getVector());
		vector_list.pmergeMe_sort();
		std::cout << "After: " << std::endl;
		printVector(vector_list.getVector());
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}
