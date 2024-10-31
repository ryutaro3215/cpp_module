/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuba <rmatsuba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 16:06:00 by rmatsuba          #+#    #+#             */
/*   Updated: 2024/10/31 20:20:53 by rmatsuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/AForm.hpp"
#include "./includes/PresidentialPardonForm.hpp"
#include "./includes/Bureaucrat.hpp"
#include "./includes/RobotomyRequestForm.hpp"
#include "./includes/ShrubberyCreationForm.hpp"

int main(void) {
	/* { */
	/* 	Bureaucrat  a("name", 1); */
	/* 	PresidentialPardonForm pre("pre"); */

	/* 	a.signForm(pre); */
	/* 	try { */
	/* 		pre.execute(a); */
	/* 	} catch (std::exception &e) { */
	/* 		std::cerr <<  e.what() << std::endl; */
	/* 	} */
	/* } */
	/* { */
	/* 	Bureaucrat a("jack", 2); */
	/* 	RobotomyRequestForm robot("robot"); */

	/* 	a.signForm(robot); */
	/* 	try { */
	/* 		robot.execute(a); */
	/* 	} catch (std::exception &e) { */
	/* 		std::cerr << e.what() << std::endl; */
	/* 	} */
	/* } */
	{
		Bureaucrat a("jack", 2);
		ShrubberyCreationForm shrub("shrub");
		ShrubberyCreationForm shrub2("shrub2");

		a.signForm(shrub2);
		try {
			shrub2.execute(a);
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
	}
	return 0;
}

