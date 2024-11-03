/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuba <rmatsuba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 15:35:31 by rmatsuba          #+#    #+#             */
/*   Updated: 2024/10/31 20:19:54 by rmatsuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ShrubberyCreationForm.hpp"
#include "./includes/Bureaucrat.hpp"
#include "./includes/AForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137) {
	std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
	target_ = "default";
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : AForm("ShrubberyCreationForm", 145, 137) {
	std::cout << "ShrubberyCreationForm constructor called" << std::endl;
	target_ = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other) {
	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
	target_ = other.target_;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
	std::cout << "ShrubberyCreationForm assignment operator called" << std::endl;
	if (this == &other)
		return *this;
	AForm::operator=(other);
	this->target_ = other.target_;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
	if (executor.getGrade() > getExecGrade())
		throw AForm::GradeTooLowException();

	if (!getIsSigned())
		throw AForm::isNotsignedException();
	std::ofstream shrubberyfile(target_ + "_shrubbery");
	if (!shrubberyfile) {
		std::cerr << "Failed to open file" << std::endl;
		return ;
	}
	std::cout << "ShrubberyCreationForm is executed" << std::endl;
	shrubberyfile << "      *      " << std::endl
		<< "     ***     " << std::endl
		<< "    *****    " << std::endl
		<< "   *******   " << std::endl
		<< "  *********  " << std::endl
		<< " *********** " << std::endl
		<< "*************" << std::endl
		<< "     |||     " << std::endl
		<< "     |||     " << std::endl;
	shrubberyfile.close();
}
