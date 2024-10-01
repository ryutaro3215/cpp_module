/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuba <rmatsuba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 19:47:59 by rmatsuba          #+#    #+#             */
/*   Updated: 2024/10/01 13:40:00 by rmatsuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal() {
	std::cout << "WrongCat Default constructor called" << std::endl;
	setType("WrongCat");
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat Destructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &other) {
	std::cout << "WrongCat Copy constructor called" << std::endl;
	setType(other.getType());
}

WrongCat &WrongCat::operator=(const WrongCat &other) {
	std::cout << "WrongCat Assignation operator called" << std::endl;
	if (this == &other)
		return *this;
	setType(other.getType());
	return *this;
}

void WrongCat::makeSound() const {
	std::cout << "Meow Meow" << std::endl;
}
