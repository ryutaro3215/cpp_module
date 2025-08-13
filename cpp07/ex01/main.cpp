/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuba <rmatsuba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:48:22 by rmatsuba          #+#    #+#             */
/*   Updated: 2024/12/04 17:01:13 by rmatsuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include "test.hpp"
#include <iostream>


int main(void) {
	int array1[] = {1, 2, 3, 4, 5};
	char array2[] = {'a', 'b', 'c', 'd', 'e'};
	std::string array3[] = {"one", "two", "three", "four", "five"};
	Test array4[] = {Test(1, "one"), Test(2, "two"), Test(3, "three"), Test(4, "four"), Test(5, "five")};

	{
		std::cout << "int array: ";
		iter(array1, 5, print<int>);
		std::cout << std::endl;
	}
	{
		std::cout << "char array: ";
		iter(array2, 5, print<char>);
		std::cout << std::endl;
	}
	{
		std::cout << "string array: ";
		iter(array3, 5, print<std::string>);
		std::cout << std::endl;
	}
	{
		std::cout << "Test array: ";
		iter(array4, 5, print<Test>);
		std::cout << std::endl;
	}
	return 0;
}
