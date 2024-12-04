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
#include "Array.hpp"

int main() {
	std::cout << "=============Constructor test=============" << std::endl;
	{
		Array<int> *int1 = new Array<int>(5);
		std::cout << "int1: " << int1->getArray(0) << std::endl;
		Array<int> int2 = Array<int>(*int1); 
		std::cout << "int2: " << int2.getArray(2) << std::endl;
		Array<int> *int3;
		int3 = int1;
		std::cout << "int3: " << int3->getArray(1) << std::endl;
	}
	{
		Array<std::string> *str1 = new Array<std::string>(5);
		std::cout << "str1: " << str1->getArray(0) << std::endl;
		Array<std::string> str2 = Array<std::string>(*str1);
		std::cout << "str2: " << str2.getArray(2) << std::endl;
		Array<std::string> *str3;
		str3 = str1;
		std::cout << "str3: " << str3->getArray(1) << std::endl;
	}
}
