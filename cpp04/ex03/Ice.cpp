/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuba <rmatsuba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 10:31:45 by rmatsuba          #+#    #+#             */
/*   Updated: 2024/10/18 10:51:02 by rmatsuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Ice.hpp"

Ice::Ice() : AMateria("ice") {
	std::cout << "Ice constructor called" << std::endl;
}

Ice::~Ice() {
	std::cout << "Ice destructor called" << std::endl;
}

Ice::Ice(const Ice &other) : AMateria(other.type_) {
	std::cout << "Ice copy constructor called" << std::endl;
}

Ice &Ice::operator=(const Ice &other) {
	std::cout << "Ice assignation operator called" << std::endl;
	if (this == &other)
		return *this;
	type_ = getType(); 
	return *this;
}

AMateria *Ice::clone() const {
	return new Ice(*this);
}
