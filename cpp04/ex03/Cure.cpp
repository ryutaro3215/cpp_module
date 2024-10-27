/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuba <rmatsuba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 11:58:32 by rmatsuba          #+#    #+#             */
/*   Updated: 2024/10/28 00:56:59 by rmatsuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/Cure.hpp"

Cure::Cure() : AMateria("cure") {
		std::cout << "Cure constructor called" << std::endl;
}

Cure::~Cure() {
	std::cout << "Cure destructor called" << std::endl;
}

Cure::Cure(const Cure &other) : AMateria(other.type_) {
	std::cout << "Cure copy constructor called" << std::endl;
}

Cure &Cure::operator=(const Cure &other) {
	std::cout << "Cure assignmation operator called" << std::endl;
	if (this == &other)
		return *this;
	this->type_ = other.getType();
	return *this;
}

AMateria *Cure::clone() const {
	return new Cure(*this);
}

void Cure::use(ICharacter &target) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
