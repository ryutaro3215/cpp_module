/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuba <rmatsuba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 15:38:49 by rmatsuba          #+#    #+#             */
/*   Updated: 2024/11/27 17:51:25 by rmatsuba         ###   ########.fr       */
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
		a.signForm(f);
		std::cout << a.getName() << " signed " << f.getName() << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		b.signForm(f2);
	} catch(std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}
