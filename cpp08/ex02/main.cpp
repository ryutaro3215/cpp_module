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

int main() {
    std::cout << "== MutantStack Basic Test ==" << std::endl;

    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);

    std::cout << "Top element: " << mstack.top() << std::endl;

    mstack.pop();

    std::cout << "Size after pop: " << mstack.size() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    std::cout << "Iterating forward:" << std::endl;
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    for (; it != ite; ++it) {
        std::cout << *it << std::endl;
    }

    std::cout << "Iterating in reverse:" << std::endl;
    MutantStack<int>::reverse_iterator rit = mstack.rbegin();
    MutantStack<int>::reverse_iterator rite = mstack.rend();
    for (; rit != rite; ++rit) {
        std::cout << *rit << std::endl;
    }

    std::cout << "== Copy constructor test ==" << std::endl;
    MutantStack<int> copyStack(mstack);
    for (MutantStack<int>::iterator cit = copyStack.begin(); cit != copyStack.end(); ++cit) {
        std::cout << *cit << " ";
    }
    std::cout << std::endl;

    std::cout << "== Assignment operator test ==" << std::endl;
    MutantStack<int> assignedStack;
    assignedStack = mstack;
    for (MutantStack<int>::iterator ait = assignedStack.begin(); ait != assignedStack.end(); ++ait) {
        std::cout << *ait << " ";
    }
    std::cout << std::endl;

    return 0;
}
