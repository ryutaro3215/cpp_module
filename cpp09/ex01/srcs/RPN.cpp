#include "RPN.hpp"
#include <sstream>

rpn::rpn() : _count(0) {};

rpn::~rpn() {};

rpn::rpn(const rpn& other) : _stack(other._stack), _count(other._count) {};

rpn& rpn::operator=(const rpn& other) {
	if (this == &other)
		return *this;
	this->_stack = other._stack;
	return *this;
};

void rpn::execRPN(std::string input) {
	size_t el_count = count_element(input);
	for (size_t i = 0; i < el_count; i++) {
		std::string el = getElement(input);
		if (el == "")
			break ;
		type el_type = checkElType(el);
		switch (el_type) {
			case NUM:
				_stack.push(el);
				_count++;
				break;
			case OPR:
				calculate(el);
				break;
			default:
				throw invalid_argument();
				break;
		}
	}
	std::cout << _stack.top() << std::endl;
	if (_count != 1)
		throw invalid_expression();
	return ;
}

void rpn::calculate(std::string el) {
	if (_count < 2)
		throw invalid_expression();

	std::string top = _stack.top();
	_stack.pop();
	std::string second = _stack.top();
	_stack.pop();
	_count -= 2;
	float fl_top = 0.0f;
	float fl_second = 0.0f;

	std::istringstream tss(top);
	tss >> fl_top;

	std::istringstream sss(second);
	sss >> fl_second;

	float result = 0.0f;
	ope ope_type = checkOperator(el); 
	switch (ope_type) {
		case PLUS:
			result =  fl_second + fl_top;
			break;
		case MINUX:
			result = fl_second - fl_top;
			break;
		case PROD:
			result = fl_second * fl_top;
			break;
		case DIVI:
			if (fl_top == 0.0f)
				throw invalid_argument();
			result = fl_second / fl_top;
			break;
		default:
			throw invalid_argument();
	}
	if (result > INT_MAX)
		throw int_overflow();

	std::ostringstream oss;
	oss << result;
	std::string new_el = oss.str();
	_stack.push(new_el);
	_count++;
}

ope rpn::checkOperator(std::string op) {
	if (op == "+")
		return PLUS;
	else if (op == "-")
		return MINUX;
	else if (op == "*")
		return PROD;
	else if (op == "/")
		return DIVI;
	else
		return EXCE;
}

size_t rpn::count_element(const std::string& input) {
	std::istringstream iss(input);
	size_t n = 0; 
	std::string tok;
	while (iss >> tok)
		++n;
	return n;
}

std::string rpn::getElement(std::string& input) {
	size_t i = 0;
	size_t input_size = input.size();
	while (i < input_size && std::isspace(input[i]))
		i++;
	if (i == input_size)
		return "";
	size_t k = i;
	while (k < input_size && !std::isspace(input[k]))
		k++;
	std::string el = input.substr(i, k - i);
	input.erase(0, k);
	while (!input.empty() && std::isspace(input[0]))
		input.erase(0, 1);
	return el;
}

type rpn::checkElType(std::string el) {
	std::string valid_number[] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};
	std::string valid_operand[] = {"+", "-", "*", "/"};

	for (size_t i = 0; i < sizeof(valid_number) / sizeof(std::string); i++) {
		if (el == valid_number[i])
			return NUM;
	}
	for (size_t k = 0; k < sizeof(valid_operand) / sizeof(std::string); k++) {
		if (el == valid_operand[k])
			return OPR;
	}
	return ERR;
};

const char* rpn::invalid_expression::what() const throw() {
	return "Invalid Expression";
}

const char* rpn::invalid_argument::what() const throw() {
	return "Invalid argument";
}

const char* rpn::int_overflow::what() const throw() {
	return "Int Overflow";
}


