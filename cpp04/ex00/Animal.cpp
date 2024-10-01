/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuba <rmatsuba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 11:04:14 by rmatsuba          #+#    #+#             */
/*   Updated: 2024/10/01 13:39:21 by rmatsuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Animal.hpp"

Animal::Animal() : type_("Animal") {
	std::cout << "Animal constructor called" << std::endl;
}

Animal::~Animal() {
	std::cout << "Animal destructor called" << std::endl;
}

Animal::Animal(const Animal &other) {
	std::cout << "Animal copy constructor called" << std::endl;
	setType(other.getType());
}

Animal &Animal::operator=(const Animal &other) {
	std::cout << "Animal assignment operator called" << std::endl;
	if (this == &other)
		return *this;
	setType(other.getType());
	return *this;
}

void	Animal::setType(std::string type) {
	this->type_ = type;
}

std::string Animal::getType() const {
	return this->type_;
}

void	Animal::makeSound() const {
	std::cout << "Animal sound" << std::endl;
}
