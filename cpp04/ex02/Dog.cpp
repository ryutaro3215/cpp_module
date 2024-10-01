/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuba <rmatsuba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 11:52:12 by rmatsuba          #+#    #+#             */
/*   Updated: 2024/09/28 21:41:28 by rmatsuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Dog.hpp"

Dog::Dog() : Animal() {
	std::cout << "Dog constructor called" << std::endl;
	setType("Dog");
	_brain = new Brain();
}

Dog::~Dog() {
	std::cout << "Dog destructor called" << std::endl;
	delete _brain;
}

Dog::Dog(const Dog &other) : Animal(other) {
	std::cout << "Dog copy constructor called" << std::endl;
	setType(other.getType());
	_brain = new Brain(*other.getBrain());
}

Dog &Dog::operator=(const Dog &other) {
	std::cout << "Dog assgnment operator called" << std::endl;
	if (this == &other)
		return *this;
	Animal::operator=(other);
	Brain *tmp = _brain;
	_brain = new Brain(*other.getBrain());
	setType(other.getType());
	delete tmp;
	return (*this);
}

void	Dog::makeSound() const {
	std::cout << "Bow wow" << std::endl;
}

Brain *Dog::getBrain() const {
	return _brain;
}

void	Dog::setBrain(Brain *brain) {
	_brain = brain;
}
