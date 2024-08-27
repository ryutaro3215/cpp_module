/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuba <rmatsuba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 19:12:05 by rmatsuba          #+#    #+#             */
/*   Updated: 2024/07/05 19:43:08 by rmatsuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Fixed.hpp"

Fixed::Fixed() : value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int val)
{
	std::cout << "Int constructor called" << std::endl;
	setRawBits(val << frac_bits);
}

Fixed::Fixed(const float val)
{
	std::cout << "Floating constructor called" << std::endl;
	setRawBits(static_cast<int>(roundf(val * (1 << frac_bits))));
}

Fixed::Fixed(const Fixed& other) : value(other.value)
{
	std::cout << "Copy constructor called" << std::endl;
	this->value = other.value;
}

Fixed	&Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this == &other)
		return (*this);
	this->value = other.value;
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits() const
{
	return (this->value);
}

void	Fixed::setRawBits(int val)
{
	this->value = val;
}

int	Fixed::toInt() const
{
	return (this->value >> frac_bits);
}

float	Fixed::toFloat() const
{
	return (static_cast<float>(this->value) / (1 << frac_bits));
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return (out);
}
