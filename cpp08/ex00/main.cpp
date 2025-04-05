/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuba <rmatsuba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 14:11:50 by rmatsuba          #+#    #+#             */
/*   Updated: 2024/12/06 14:51:14 by rmatsuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <array>
#include <deque>
#include <list>
#include "easyfind.hpp"

int main(void) {
	{
		std::cout << "==== vector ====" << std::endl;
		std::vector<int> vec;
		vec.push_back(1);
		vec.push_back(2);
		vec.push_back(3);
		try {
			std::vector<int>::iterator it = easyfind(vec, 4);
			std::cout << "Found: " << *it << std::endl;
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}

	{
		std::cout << "==== array ====" << std::endl;
		std::array<int, 3> arr = {1, 2, 3};
		try {
			std::array<int, 3>::iterator it = easyfind(arr, 2);
			std::cout << "Found: " << *it << std::endl;
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}

	{
		std::cout << "==== deque ====" << std::endl;
		std::deque<int> deq;
		deq.push_back(1);
		deq.push_back(2);
		deq.push_back(3);
		try {
			std::deque<int>::iterator it = easyfind(deq, 3);
			std::cout << "Found: " << *it << std::endl;
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
	
	{
		std::cout << "==== list ====" << std::endl;
		std::list<int> lst;
		lst.push_back(1);
		lst.push_back(2);
		lst.push_back(3);
		try {
			std::list<int>::iterator it = easyfind(lst, 2);
			std::cout << "Found: " << *it << std::endl;
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
}
