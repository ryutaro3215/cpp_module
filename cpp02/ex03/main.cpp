/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuba <rmatsuba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 19:11:51 by rmatsuba          #+#    #+#             */
/*   Updated: 2024/07/21 21:09:42 by rmatsuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

int main(void)
{
	Point a = Point(0, 0);
	Point b = Point(2, 0);
	Point c = Point(0, 2);
	Point p1 = Point(1, 1);
	Point p2 = Point(0, 0);
	Point p3 = Point(1, 0);
	Point p4 = Point(2, 2);
	Point p5 = Point(-2, -2);


	if (bsp(a, b, c, p1))
		std::cout << "Point is in the triangle" << std::endl;
	else
		std::cout << "Point is not in the triangle" << std::endl;

	if (bsp(a, b, c, p2))
		std::cout << "Point is in the triangle" << std::endl;
	else
		std::cout << "Point is not in the triangle" << std::endl;

	if (bsp(a, b, c, p3))
		std::cout << "Point is in the triangle" << std::endl;
	else
		std::cout << "Point is not in the triangle" << std::endl;

	if (bsp(a, b, c, p4))
		std::cout << "Point is in the triangle" << std::endl;
	else
		std::cout << "Point is not in the triangle" << std::endl;

	if (bsp(a, b, c, p5))
		std::cout << "Point is in the triangle" << std::endl;
	else
		std::cout << "Point is not in the triangle" << std::endl;

	return (0);
}
