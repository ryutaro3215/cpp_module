/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuba <rmatsuba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 13:52:06 by rmatsuba          #+#    #+#             */
/*   Updated: 2024/07/21 21:01:54 by rmatsuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class	Point : public Fixed
{
	private:
		Fixed const	_x;
		Fixed const	_y;
	public:
		Point();
		Point(const Fixed &x, const Fixed &y);
		Point(const Point &point);
		~Point();
		Point	&operator=(const Point &point);
		Fixed	getX() const;
		Fixed	getY() const;
};

bool	bsp(Point const a, Point const b, Point const c, Point const point);

#endif
