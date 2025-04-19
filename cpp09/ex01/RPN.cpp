/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuba <rmatsuba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 14:16:39 by rmatsuba          #+#    #+#             */
/*   Updated: 2025/04/19 16:44:49 by rmatsuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN &src) {
	*this = src;
}

RPN &RPN::operator=(const RPN &src) {
	if (this != &src) {
		this->_stack = src._stack;
	}
	return *this;
}

RPN::~RPN() {}

void RPN::calculate(const std::string &expression) {
	std::istringstream iss(expression);
	std::string token;
	int result;
	while (iss >> token) {
		if (token.length() != 1) {
			std::cerr << "Error: Invalid token length" << std::endl;
			return;
		}
		char c = token[0];
		if (isdigit(c)) {
			/* std::cout << "Pushing: " << c << std::endl; */
			_stack.push(c - '0');
		}
		else if (c == '+' || c == '-' || c == '*' || c == '/') {
			if (_stack.size() < 2) {
				std::cerr << "Error: Not enough operands" << std::endl;
				return ;
			}
			int b = _stack.top();
			_stack.pop();
			int a = _stack.top();
			_stack.pop();
			switch (c) {
				case '+':
					result = a + b;
					break;
				case '-':
					result = a - b;
					break;
				case '*':
					result = a * b;
					break;
				case '/':
					if (b == 0) {
						std::cerr << "Error: Division by zero" << std::endl;
						return ;
					}
					result = a / b;
					break;
			}
			/* std::cout << "Performing operation: " << a << " " << c << " " << b << std::endl; */
			_stack.push(result);
		} else {
			std::cerr << "Error: Invalid character" << std::endl;
			return ;
		}
	}
	if (_stack.size() != 1) {
		std::cerr << "Error: Invalid expression" << std::endl;
		return ;
	}
	std::cout << "Result: " <<  _stack.top() << std::endl;
	return ;
}
