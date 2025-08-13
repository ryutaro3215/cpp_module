/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuba <rmatsuba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 16:39:21 by rmatsuba          #+#    #+#             */
/*   Updated: 2024/11/27 18:09:34 by rmatsuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/RobotomyRequestForm.hpp"
#include "./includes/Bureaucrat.hpp"
#include "./includes/AForm.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45) {
	target_ = "default";
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target) : AForm("RobotomyRequestForm", 72, 45) {
	target_ = target;
} 

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other) {
	target_ = other.target_;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
	if (this == &other)
		return *this;
	AForm::operator=(other);
	this->target_ = other.target_;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

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


