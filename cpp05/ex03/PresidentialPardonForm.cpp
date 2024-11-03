/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuba <rmatsuba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 14:17:38 by rmatsuba          #+#    #+#             */
/*   Updated: 2024/10/31 16:23:32 by rmatsuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/PresidentialPardonForm.hpp"
#include "./includes/Bureaucrat.hpp"
#include "./includes/AForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5) {
	std::cout << "PresidentialPardonForm default constructor called" << std::endl;
	target_ = "default";
}

PresidentialPardonForm::PresidentialPardonForm(const std::string target)
	: AForm("PresidentialPardonForm", 25, 5) {
		std::cout << "PresidentialPardonForm constructor called" << std::endl;
		target_ = target;
	}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm(other) {
	std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
	target_  = other.target_;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other) {
	std::cout << "PresidentialPardonForm assignment operator called" << std::endl;
	if (this == &other)
		return *this;
	AForm::operator=(other);
	this->target_ = other.target_;
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << "PresidentialPardonForm destructor called" << std::endl;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const {
	if (executor.getGrade() > getExecGrade())
		throw AForm::GradeTooLowException();
	if (!getIsSigned())
		throw AForm::isNotsignedException();
	std::cout << target_ << " has been pardoned by Zafod Beeblebrox" << std::endl;
}
