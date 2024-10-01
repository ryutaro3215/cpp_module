/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuba <rmatsuba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 11:52:12 by rmatsuba          #+#    #+#             */
/*   Updated: 2024/10/01 13:39:31 by rmatsuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Dog.hpp"

Dog::Dog() : Animal() {
	std::cout << "Dog constructor called" << std::endl;
	setType("Dog");
}

Dog::~Dog() {
	std::cout << "Dog destructor called" << std::endl;
}

Dog::Dog(const Dog &other) {
	std::cout << "Dog copy constructor called" << std::endl;
	setType(other.getType());
}

Dog &Dog::operator=(const Dog &other) {
	std::cout << "Dog assgnment operator called" << std::endl;
	if (this == &other)
		return *this;
	Animal::operator=(other);
	setType(other.getType());
	return (*this);
}

void	Dog::makeSound() const {
	std::cout << "Bow wow" << std::endl;
}
