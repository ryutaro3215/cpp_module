/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuba <rmatsuba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 15:53:36 by rmatsuba          #+#    #+#             */
/*   Updated: 2024/12/06 19:40:50 by rmatsuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <algorithm>
#include <vector>
#include "Span.hpp"


int main(void) {
	std::cout << "==== default test ====" << std::endl;
	{ 
		Span sp = Span(5); 
		sp.addNumber(6); 
		sp.addNumber(3); 
		sp.addNumber(17); 
		sp.addNumber(9);
		sp.addNumber(11);
		for (size_t i = 0; i < sp.getArray().size(); i++) {
			std::cout << "Span element[" << i << "]: " << sp.getArray()[i] << std::endl;
	 }
		std::cout << "short span: "; 
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << "long span: ";
		std::cout << sp.longestSpan() << std::endl;
	}
	std::cout << "==== few element test ====" << std::endl;
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		try {
			std::cout << "short span: "; 
			std::cout << sp.shortestSpan() << std::endl;
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		try {
			std::cout << "long span: ";
			std::cout << sp.longestSpan() << std::endl;
		} catch (std::exception &e) { 
			std::cout << e.what() << std::endl; 
		}
	}
	std::cout << "==== MultipleNumber test ====" << std::endl;
	{
		Span sp = Span(10);
		std::vector<int> vec;
		for (int i = 0; i < 10; i++) {
			vec.push_back(i);
		}
		sp.addMultipleNumbers(vec.begin(), vec.end());
		try {
			std::cout << "short span: "; 
			std::cout << sp.shortestSpan() << std::endl;
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		try {
			std::cout << "long span: ";
			std::cout << sp.longestSpan() << std::endl;
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << "==== Error thow test ====" << std::endl;
	{
		Span sp = Span(10);
		try {
			std::cout << "short span: "; 
			std::cout << sp.shortestSpan() << std::endl;
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		try {
			std::cout << "long span: ";
			std::cout << sp.longestSpan() << std::endl;
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
	return 0;
}
