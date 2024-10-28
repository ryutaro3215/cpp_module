/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuba <rmatsuba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 15:38:49 by rmatsuba          #+#    #+#             */
/*   Updated: 2024/10/28 15:55:07 by rmatsuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/Bureaucrat.hpp"
#include "./includes/Form.hpp"
#include <iostream>


int main(void)
{
	Bureaucrat a("A", 1);
	Bureaucrat b("B", 150);
	Form f("F", 10, 1);
	Form f2("F2", 10, 1);

	try {
		Form f1("F1", 0, 1);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		Form f2("F2", 1, 0);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		Form f3("F3", 151, 1);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		Form f4("F4", 1, 151);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		f.beSigned(a);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		f.beSigned(b);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		a.signForm(f);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	try {
	a.signForm(f2);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
