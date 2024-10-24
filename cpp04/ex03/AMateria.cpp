/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuba <rmatsuba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 11:55:19 by rmatsuba          #+#    #+#             */
/*   Updated: 2024/10/24 13:52:11 by rmatsuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/AMateria.hpp"
#include "./includes/ICharacter.hpp"

AMateria::AMateria() : type_("default") {
	std::cout << "Default AMateria constructor called" << std::endl;
}

AMateria::AMateria(std::string const &type) : type_(type) {
	std::cout << "AMateria constructor called" << std::endl;
}

AMateria::~AMateria() {
	std::cout << "AMateria destructor called" << std::endl;
}

std::string const &AMateria::getType() const {
	return this->type_;
}

void	AMateria::use(ICharacter &target) {
	std::cout << "AMateria is used to " << target.getName() << std::endl;
}
