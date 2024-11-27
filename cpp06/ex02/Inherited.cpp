/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Inherited.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuba <rmatsuba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 19:44:05 by rmatsuba          #+#    #+#             */
/*   Updated: 2024/11/27 20:15:29 by rmatsuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Inherited.hpp"
#include <iostream>

A::A() noexpect : m_name("A") {}
const std::string &A::getName(void) const {
	return m_name;
}
B::B() noexpect : m_name("B") {}
const std::string &B::getName(void) const {
	return m_name;
}

C::C() noexpect : m_name("C") {}
const std::string &C::getName(void) const {
	return m_name;
}

Base *generate(void) {
	srand(time(NULL));
	int i = rand() % 3;
	switch (i) {
		case 0:
			return new A;
		case 1:
			return new B;
		case 2:
			return new C;
	}
}

void identify(Base *p) {
	if (dynamic_cast<A*>(p)) {
		A &a = dynamic_cast<A&>(*p);
		std::cout << a.getName() << std::endl;
	}
	else if (dynamic_cast<B*>(p)) {
		B &b = dynamic_cast<B&>(*p);
		std::cout << b.getName() << std::endl;
	}
	else if (dynamic_cast<C*>(p)) {
		C &c = dynamic_cast<C&>(*p);
		std::cout << c.getName() << std::endl;
	}
	else
		std::cout << "Unknown" << std::endl;
}

void identify(Base &p) {
	try {
		A &a = dynamic_cast<A&>(p);
		std::cout << a.getName() << std::endl;
	} catch (std::bad_cast &e) {
		try {
			B &b = dynamic_cast<B&>(p);
			std::cout << b.getName() << std::endl;
		} catch (std::bad_cast &e) {
			try {
				C &c = dynamic_cast<C&>(p);
				std::cout << c.getName() << std::endl;
			} catch (std::bad_cast &e) {
				std::cout << "Unknown" << std::endl;
			}
		}
	}
}
