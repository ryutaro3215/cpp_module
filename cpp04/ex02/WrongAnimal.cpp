/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuba <rmatsuba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 19:44:15 by rmatsuba          #+#    #+#             */
/*   Updated: 2024/09/28 21:40:56 by rmatsuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("WrongAnimal") {
	std::cout << "WrongAnimal Default constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal Destructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) {
	std::cout << "WrongAnimal Copy constructor called" << std::endl;
	setType(other.getType());
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other) {
	std::cout << "WrongAnimal Assignation operator called" << std::endl;
	if (this == &other)
		return *this;
	setType(other.getType());
	return *this;
}

std::string WrongAnimal::getType() const {
	return _type;
}

void WrongAnimal::setType(std::string type) {
	_type = type;
}

void	WrongAnimal::makeSound() const {
	std::cout << "WrongAnimal sound" << std::endl;
}
