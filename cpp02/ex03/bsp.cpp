/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuba <rmatsuba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 20:34:58 by rmatsuba          #+#    #+#             */
/*   Updated: 2024/07/21 20:57:56 by rmatsuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Point.hpp"
# include "Fixed.hpp"

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed	denominator = ((b.getY() - c.getY()) * (a.getX() - c.getX()) +
			(c.getX() - b.getX()) * (a.getY() - c.getY()));
	Fixed u = ((b.getY() - c.getY()) * (point.getX() - c.getX()) + 
			(c.getX() - b.getX()) * (point.getY() - c.getY())) / denominator;
	Fixed v = ((c.getY() - a.getY()) * (point.getX() - c.getX()) + 
			(a.getX() - c.getX()) * (point.getY() - c.getY())) / denominator;
	float	w = 1 -  u.toFloat() - v.toFloat();

	if (u >= 0 && v >= 0 && w >= 0)
		return (true);
	return (false);
}
