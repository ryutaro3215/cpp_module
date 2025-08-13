/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuba <rmatsuba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 02:08:36 by rmatsuba          #+#    #+#             */
/*   Updated: 2024/11/27 18:26:42 by rmatsuba         ###   ########.fr       */
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

AForm *Intern::makePresidentialPardonForm(const std::string &target) {
	return new PresidentialPardonForm(target);
}

AForm *Intern::makeRobotomyRequestForm(const std::string &target) {
	return new RobotomyRequestForm(target);
}

AForm *Intern::makeShrubberyCreationForm(const std::string &target) {
	return new ShrubberyCreationForm(target);
}

AForm *Intern::makeForm(std::string name, std::string target) {
	const int formNumber = 3;
	std::string form_names[formNumber] = {
		"PresidentialPardonForm",
		"RobotomyRequestForm",
		"ShrubberyCreationForm"
	};
	AForm *(*form_creators[formNumber])(const std::string &target) = {
		makePresidentialPardonForm,
		makeRobotomyRequestForm,
		makeShrubberyCreationForm
	};
	for (int i = 0; i < formNumber; i++) {
		if (name == form_names[i]) {
			std::cout << "Intern creates " << form_names[i] << std::endl;
			return (form_creators[i])(target);
		}
	}
	std::cout << "Intern cannot create " << name << std::endl;
	return NULL;
}
