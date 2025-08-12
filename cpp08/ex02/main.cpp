/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuba <rmatsuba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 17:52:46 by rmatsuba          #+#    #+#             */
/*   Updated: 2024/12/08 19:11:24 by rmatsuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <list>


int main() {
	std::cout << "==== deque ====" << std::endl;
	{
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << "mstack top: ";
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << "mstack size: ";
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << "mstack: " << *it << std::endl;
			++it;
		}
	}
	std::cout << "==== list ====" << std::endl;
	{
		MutantStack<int, std::list<int> > mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << "mstack top: ";
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << "mstack size: ";
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
		MutantStack<int, std::list<int> >::iterator it = mstack.begin();
		MutantStack<int, std::list<int> >::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << "mstack: " << *it << std::endl;
			++it;
		}
		std::stack<int, std::list<int> > s(mstack);
	}
	return 0;
}
