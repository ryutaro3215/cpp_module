#include "RPN.hpp"

int main(int argc, char **argv) {
	// if (argc != 2)
	// 	std::cerr << "Invalid argument number" << std::endl;
	(void)argv;
	(void)argc;
	rpn stack;
	// try {
	// 	std::string test1 = "7 * 7 / 1";
	// 	stack.execRPN(test1);
	// } catch (std::exception &e) {
	// 	std::cerr << e.what() << std::endl;
	// }

	// try {
	// 	std::string test1 = "7 7 * / 0";
	// 	stack.execRPN(test1);
	// } catch (std::exception &e) {
	// 	std::cerr << e.what() << std::endl;
	// }
	//
	// try {
	// 	std::string test1 = "7 10 *";
	// 	stack.execRPN(test1);
	// } catch (std::exception &e) {
	// 	std::cerr << e.what() << std::endl;
	// }
	//
	// try {
	// 	std::string test1 = "7 -7 + 1 +";
	// 	stack.execRPN(test1);
	// } catch (std::exception &e) {
	// 	std::cerr << e.what() << std::endl;
	// }

	try {
		std::string test1 = "7 7 / 1 *";
		stack.execRPN(test1);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
