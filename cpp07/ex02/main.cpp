/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuba <rmatsuba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 17:14:34 by rmatsuba          #+#    #+#             */
/*   Updated: 2024/12/04 19:50:10 by rmatsuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Array.hpp"

int main() {
	std::cout << "========== Test: default constructor ==========\n";
	Array<int> a;
	std::cout << "Size of a: " << a.size() << std::endl;

	std::cout << "\n========== Test: constructor with size ==========\n";
	Array<int> b(5);
	for (unsigned int i = 0; i < b.size(); ++i)
		b[i] = i * 10;
	for (unsigned int i = 0; i < b.size(); ++i)
		std::cout << "b[" << i << "] = " << b.getArray(i) << std::endl;

	std::cout << "\n========== Test: copy constructor ==========\n";
	Array<int> c(b);
	for (unsigned int i = 0; i < c.size(); ++i)
		std::cout << "c[" << i << "] = " << c[i] << std::endl;

	std::cout << "\n========== Test: assignment operator ==========\n";
	Array<int> d;
	d = c;
	for (unsigned int i = 0; i < d.size(); ++i)
		std::cout << "d[" << i << "] = " << d.getArray(i) << std::endl;

	std::cout << "\n========== Test: string array ==========\n";
	Array<std::string> s(3);
	s[0] = "hello";
	s[1] = "template";
	s[2] = "world";

	for (unsigned int i = 0; i < s.size(); ++i)
		std::cout << "s[" << i << "] = " << s[i] << std::endl;

	std::cout << "\n========== Test: out of bounds access ==========\n";
	try {
		std::cout << s[5] << std::endl;
	} catch (std::out_of_range& e) {
		std::cout << "Caught exception: " << e.what() << std::endl;
	}

	std::cout << "\n========== Test: self-assignment ==========\n";
	c = c;
	for (unsigned int i = 0; i < c.size(); ++i)
		std::cout << "c[" << i << "] = " << c[i] << std::endl;

	return 0;
}
