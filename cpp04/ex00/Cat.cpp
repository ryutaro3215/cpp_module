/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuba <rmatsuba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 11:29:06 by rmatsuba          #+#    #+#             */
/*   Updated: 2024/09/27 12:21:01 by rmatsuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal() {
	std::cout << "Cat constructor called" << std::endl;
	setType("Cat");
}

Cat::~Cat() {
	std::cout << "Cat destructor called" << std::endl;
}

Cat::Cat(const Cat &other) {
	std::cout << "Cat copy constructor called" << std::endl;
	setType(other.getType());
}

Cat	&Cat::operator=(const Cat &other) {
	std::cout << "Cat assignment operator called" << std::endl;
	if (this == &other)
		return *this;
	setType(other.getType());
	return *this;
}

void	Cat::makeSound() const {
	std::cout << "Meow Meow" << std::endl;
}
