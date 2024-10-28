/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuba <rmatsuba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 15:38:49 by rmatsuba          #+#    #+#             */
/*   Updated: 2024/10/28 12:08:30 by rmatsuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/Bureaucrat.hpp"
#include <iostream>


int main(void)
{
	{
		std::cout << "========normal case========" << std::endl;
		Bureaucrat b1("b1", 1);
		Bureaucrat b2("b2", 150);
		b1 = b2;
		std::cout << b1 << std::endl;
		std::cout << b2 << std::endl;
		std::cout << b1.getName() << std::endl;
		std::cout << b2.getName() << std::endl;
	}
	{
		std::cout << "========exception case========" << std::endl;
		try {
			Bureaucrat b1("b1", 0);
		} catch (Bureaucrat::GradeTooHighException &e) {
			std::cout << e.what() << std::endl;
		}
		try {
			Bureaucrat b2("b2", 151);
		} catch (Bureaucrat::GradeTooLowException &e) {
			std::cout << e.what() << std::endl;
		}
	}
	{
		std::cout << "========upgrade and downgrade case========" << std::endl;
		Bureaucrat up("up", 150);
		Bureaucrat down("down", 1);
		up.upGrade();
		down.downGrade();
		std::cout << up << std::endl;
		std::cout << down << std::endl;
	}
	{
		std::cout << "========exception case of up and down" << std::endl;
		Bureaucrat down("up", 150);
		Bureaucrat up("down", 1);
		try {
			down.downGrade();
		} catch (Bureaucrat::GradeTooLowException &e) {
			std::cout << e.what() << std::endl;
		}
		try {
			up.upGrade();
		} catch (Bureaucrat::GradeTooHighException &e) {
			std::cout << e.what() << std::endl;
		}
	}
	{
		std::cout << "========copy constructor case========" << std::endl;
		Bureaucrat b1("b1", 1);
		Bureaucrat b2(b1);
		std::cout << b1 << std::endl;
		std::cout << b2 << std::endl;
	}
	{
		std::cout << "========assignment operator case========" << std::endl;
		Bureaucrat b1("b1", 1);
		Bureaucrat b2("b2", 150);

		b2 = b1;
		std::cout << b1 << std::endl;
		std::cout << b2 << std::endl;
	}
	return 0;
}
