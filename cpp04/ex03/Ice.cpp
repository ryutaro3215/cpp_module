/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuba <rmatsuba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 10:31:45 by rmatsuba          #+#    #+#             */
/*   Updated: 2024/10/16 20:03:16 by rmatsuba         ###   ########.fr       */
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
	stdL::cout << "Ice assignation operator called" << std::endl;

}
