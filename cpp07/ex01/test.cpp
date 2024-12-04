/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuba <rmatsuba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:57:23 by rmatsuba          #+#    #+#             */
/*   Updated: 2024/12/04 17:10:56 by rmatsuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"
#include <iostream>

Test::Test() : _value(0), _name("default") {}

Test::Test(int value, std::string name) : _value(value), _name(name) {}

Test::~Test() {}

Test::Test(const Test &other) {
	*this = other;
}

Test &Test::operator=(const Test &other) {
	if (this == &other)
		return *this;
	_value = other._value;
	_name = other._name;
	return *this;
}

int Test::getValue() const {
	return _value;
}

std::string Test::getName() const {
	return _name;
}

std::ostream &operator<<(std::ostream &os, const Test &test) {
	os << "Test(" << test.getValue() << ", " << test.getName() << ")";
	return os;
}
