/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuba <rmatsuba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 19:12:05 by rmatsuba          #+#    #+#             */
/*   Updated: 2024/07/07 23:35:39 by rmatsuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Fixed.hpp"

Fixed::Fixed() : value(0)
{
	// std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int val)
{
	// std::cout << "Int constructor called" << std::endl;
	setRawBits(val << frac_bits);
}

Fixed::Fixed(const float val)
{
	// std::cout << "Floating constructor called" << std::endl;
	setRawBits(static_cast<int>(roundf(val * (1 << frac_bits))));
}

Fixed::Fixed(const Fixed& other) : value(other.value)
{
	// std::cout << "Copy constructor called" << std::endl;
	setRawBits(other.getRawBits());
}

Fixed	&Fixed::operator=(const Fixed& other)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this == &other)
		return (*this);
	this->value = other.value;
	return (*this);
}

bool	Fixed::operator>(const Fixed& other) const
{
	if (this->value > other.value)
		return (true);
	return (false);
}

bool	Fixed::operator>=(const Fixed& other) const
{
	if (this->value >= other.value)
		return (true);
	return (false);
}

bool	Fixed::operator<(const Fixed& other) const
{
	if (this->value < other.value)
		return (true);
	return (false);
}

bool	Fixed::operator<=(const Fixed& other) const
{
	if (this->value <=  other.value)
		return (true);
	return (false);
}

bool	Fixed::operator==(const Fixed& other) const
{
	if (this->value == other.value)
		return (true);
	return (false);
}

bool	Fixed::operator!=(const Fixed& other) const
{
	if (this->value != other.value)
		return (true);
	return (false);
}

Fixed	Fixed::operator+(const Fixed& other) const
{
	Fixed	obj;
	obj.setRawBits(this->value + other.value);
	return (obj);
}

Fixed	Fixed::operator-(const Fixed& other) const
{
	Fixed	obj;
	obj.setRawBits(this->value - other.value);
	return (obj);
}

Fixed	Fixed::operator*(const Fixed& other) const
{
	Fixed	obj;
	obj.setRawBits((this->value * other.value) >> frac_bits);
	return (obj);
}

Fixed	Fixed::operator/(const Fixed& other) const
{
	Fixed	obj;
	obj.setRawBits((this->value << frac_bits) / other.value);
	return (obj);
}

Fixed	&Fixed::operator++()
{
	setRawBits(this->value + 1);
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	tmp(*this);
	setRawBits(this->value + 1);
	return (tmp);
}

Fixed	&Fixed::operator--()
{
	setRawBits(this->value - 1);
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	tmp(*this);
	setRawBits(this->value - 1);
	return (tmp);
}

Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
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

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	if (a <= b)
		return (a);
	return (b);
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	if (a <= b)
		return (a);
	return (b);
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	if (a >= b)
		return (a);
	return (b);
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	if (a >= b)
		return (a);
	return (b);
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return (out);
}
