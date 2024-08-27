/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuba <rmatsuba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 19:12:05 by rmatsuba          #+#    #+#             */
/*   Updated: 2024/07/04 23:52:44 by rmatsuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Fixed.hpp"

Fixed::Fixed()
{
	value = 0;	
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) : value(other.value)
{
	std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this == &other)
		return (*this);
	this->value = other.value;
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "This is destructor" << std::endl;
}

int	Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (value);
}

void	Fixed::setRawBits(int val)
{
	std::cout << "setRawBits member function called" << std::endl;
	value = val;
}
