/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuba <rmatsuba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 10:45:34 by rmatsuba          #+#    #+#             */
/*   Updated: 2024/07/17 11:27:21 by rmatsuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
	type = "Animal";
	std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(std::string type) : type(type)
{
	std::cout << "Animal constructor called" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}

Animal::Animal(const Animal &other)
{
	std::cout << "Copy Animal constructor called" << std::endl;
	type = other.type;
}

Animal &Animal::operator=(const Animal &other)
{
	std::cout << "Assignation Animal operator called" << std::endl;
	type = other.type;
	return *this;
}

std::string	Animal::getType() const
{
	return type;
}

void	Animal::makeSound() const
{
	std::cout << "Animal sound" << std::endl;
}
