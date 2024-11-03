/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuba <rmatsuba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:37:46 by rmatsuba          #+#    #+#             */
/*   Updated: 2024/10/31 15:19:13 by rmatsuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/AForm.hpp"
#include "./includes/Bureaucrat.hpp"

const char *AForm::GradeTooHighException::what() const throw() {
	return "Grade is too high";
}

const char *AForm::GradeTooLowException::what() const throw() {
	return "Grade is too low";
}

const char *AForm::isNotsignedException::what() const throw() {
	return "Form is not signed";
}

AForm::AForm() : name_("default"), isSigned_(false), signGrade_(150), execGrade_(150) {
	std::cout << "AForm default constructor called" << std::endl;
}

AForm::AForm(const std::string name, const int signGrade, const int execGrade) : name_(name), isSigned_(false), signGrade_(signGrade), execGrade_(execGrade) {
	std::cout << "AForm constructor called" << std::endl;
	if (signGrade_ < 1 || execGrade < 1)
		throw AForm::GradeTooHighException();
	else if (signGrade_ > 150 || execGrade > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &other) : name_(other.name_), isSigned_(other.isSigned_), signGrade_(other.signGrade_), execGrade_(other.execGrade_) {
	std::cout << "AForm copy constructor called" << std::endl;
}

AForm &AForm::operator=(const AForm &other) {
	std::cout << "AForm assignment operator called" << std::endl;
	if (this == &other)
		return *this;
	isSigned_ = other.isSigned_;
	return *this;
}

AForm::~AForm() {
	std::cout << "AForm destructor called" << std::endl;
}

const std::string &AForm::getName() const {
	return name_;
}

bool AForm::getIsSigned() const {
	return isSigned_;
}

const int &AForm::getSignGrade() const {
	return signGrade_;
}

const int &AForm::getExecGrade() const {
	return execGrade_;
}

void AForm::beSigned(Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() > signGrade_)
		throw AForm::GradeTooLowException();
	isSigned_ = true;
}

std::ostream &operator<<(std::ostream &os, const AForm &form) {
	os << "AForm name: " << form.getName() << std::endl;
	os << "AForm sign grade: " << form.getSignGrade() << std::endl;
	os << "AForm exec grade: " << form.getExecGrade() << std::endl;
	os << "AForm is signed: " << form.getIsSigned() << std::endl;
	return os;
}

