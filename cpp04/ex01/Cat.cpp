/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuba <rmatsuba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 11:29:06 by rmatsuba          #+#    #+#             */
/*   Updated: 2024/10/27 20:07:29 by rmatsuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Cat.hpp"

Cat::Cat() : Animal() {
	std::cout << "Cat constructor called" << std::endl;
	setType("Cat");
	brain_ = new Brain();
}

Cat::~Cat() {
	std::cout << "Cat destructor called" << std::endl;
	delete brain_;
}

Cat::Cat(const Cat &other) : Animal(other) {
	std::cout << "Cat copy constructor called" << std::endl;
	setType(other.getType());
	brain_ = new Brain(*other.getBrain());
}

Cat	&Cat::operator=(const Cat &other) {
	std::cout << "Cat assignment operator called" << std::endl;
	if (this == &other)
		return *this;
	Animal::operator=(other);
	Brain *tmp = brain_;
	brain_ = new Brain(*other.getBrain());
	setType(other.getType());
	delete tmp;
	return *this;
}

void	Cat::makeSound() const {
	std::cout << "Meow Meow" << std::endl;
}

Brain	*Cat::getBrain() const {
	return brain_;
}

void	Cat::setBrain(Brain *brain) {
	this->brain_ = brain;
}
