/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuba <rmatsuba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 16:39:21 by rmatsuba          #+#    #+#             */
/*   Updated: 2024/10/31 15:30:50 by rmatsuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/RobotomyRequestForm.hpp"
#include "./includes/Bureaucrat.hpp"
#include "./includes/AForm.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45) {
	std::cout << "RobotomyRequestForm default constructor called" << std::endl;
	target_ = "default";
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target) : AForm("RobotomyRequestForm", 72, 45) {
	std::cout << "RobotomyRequestForm constructor called" << std::endl;
	target_ = target;
} 

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other) {
	std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
	target_ = other.target_;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
	std::cout << "RobotomyRequestForm assignment operator called" << std::endl;
	if (this == &other)
		return *this;
	AForm::operator=(other);
	this->target_ = other.target_;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
	if (executor.getGrade() > getExecGrade())
		throw AForm::GradeTooLowException();
	if (!getIsSigned())
		throw AForm::isNotsignedException();
	std::cout << "Drilling noises!!" << std::endl;
	std::srand(std::time(0));
	if (std::rand() % 2)
		std::cout << target_ << " has been robotomized successfully" << std::endl;
	else
		std::cout << target_ << " has failed to be robotomized" << std::endl;
}


