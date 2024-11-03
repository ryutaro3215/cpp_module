/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuba <rmatsuba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 02:08:36 by rmatsuba          #+#    #+#             */
/*   Updated: 2024/11/02 16:15:43 by rmatsuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/Intern.hpp"
#include "./includes/PresidentialPardonForm.hpp"
#include "./includes/RobotomyRequestForm.hpp"
#include "./includes/ShrubberyCreationForm.hpp"
#include "./includes/AForm.hpp"

Intern::Intern() {
	std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(const Intern &other) {
	std::cout << "Intern copy constructor called" << std::endl;
	*this = other;
}

Intern::~Intern() {
	std::cout << "Intern destructor called" << std::endl;
}

Intern &Intern::operator=(const Intern &other) {
	std::cout << "Intern assignment operator called" << std::endl;
	(void)other;
	return *this;
}

AForm *Intern::makeForm(std::string name, std::string target) {
	if (name == "PresidentialPardonForm") {
		return new PresidentialPardonForm(target);
	} else if (name == "RobotomyRequestForm") {
		return new RobotomyRequestForm(target);
	} else if (name == "ShrubberyCreationForm") {
		return new ShrubberyCreationForm(target);
	} else {
		std::cerr << "Invalid form name" << std::endl;
	}
	return NULL;
}
