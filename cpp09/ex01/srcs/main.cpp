#include "RPN.hpp"

int main(int argc, char **argv) {
	if (argc != 2)
		std::cerr << "Invalid argument number" << std::endl;
	rpn stack;
	try {
		stack.execRPN(argv[1]);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
