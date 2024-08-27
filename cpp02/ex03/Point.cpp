/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuba <rmatsuba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 16:17:38 by rmatsuba          #+#    #+#             */
/*   Updated: 2024/07/21 20:40:47 by rmatsuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Point.hpp"
# include "Fixed.hpp"

Point::Point() : Fixed()
{
	std::cout << "Point default constructor called" << std::endl;
}

Point::Point(const Fixed &x, const Fixed &y) : _x(Fixed(x)), _y(Fixed(y))
{
	std::cout << "Point constructor called" << std::endl;
}

Point::Point(const Point &point) : _x(Fixed(point._x)), _y(Fixed(point._y))
{
	std::cout << "Point copy constructor called" << std::endl;
}

Point::~Point()
{
	std::cout << "Point destructor called" << std::endl;
}

Point	&Point::operator=(const Point &point)
{
	if (this == &point)
		return (*this);
	*const_cast<Fixed*>(&_x) = point._x;
	*const_cast<Fixed*>(&_y) = point._y;
	return (*this);
}

Fixed	Point::getX() const
{
	return (_x);
}

Fixed	Point::getY() const
{
	return (_y);
}

