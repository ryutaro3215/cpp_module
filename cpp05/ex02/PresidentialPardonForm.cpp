/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuba <rmatsuba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 14:17:38 by rmatsuba          #+#    #+#             */
/*   Updated: 2024/11/27 18:07:20 by rmatsuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/PresidentialPardonForm.hpp"
#include "./includes/Bureaucrat.hpp"
#include "./includes/AForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5) {
	target_ = "default";
}

PresidentialPardonForm::PresidentialPardonForm(const std::string target)
	: AForm("PresidentialPardonForm", 25, 5) {
		target_ = target;
	}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm(other) {
	target_  = other.target_;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other) {
	if (this == &other)
		return *this;
	AForm::operator=(other);
	this->target_ = other.target_;
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const {
	if (executor.getGrade() > getExecGrade())
		throw AForm::GradeTooLowException();
	if (!getIsSigned())
		throw AForm::isNotsignedException();
	std::cout << target_ << " has been pardoned by Zafod Beeblebrox" << std::endl;
}
