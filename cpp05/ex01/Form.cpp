/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuba <rmatsuba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:37:46 by rmatsuba          #+#    #+#             */
/*   Updated: 2024/10/28 15:31:43 by rmatsuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/Form.hpp"
#include "./includes/Bureaucrat.hpp"

const char *Form::GradeTooHighException::what() const throw() {
	return "Grade is too high";
}

const char *Form::GradeTooLowException::what() const throw() {
	return "Grade is too low";
}

Form::Form() : name_("default"), isSigned_(false), signGrade_(150), execGrade_(150) {
	std::cout << "Form default constructor called" << std::endl;
}

Form::Form(const std::string name, const int signGrade, const int execGrade) : name_(name), isSigned_(false), signGrade_(signGrade), execGrade_(execGrade) {
	std::cout << "Form constructor called" << std::endl;
	if (signGrade_ < 1 || execGrade < 1)
		throw Form::GradeTooHighException();
	else if (signGrade_ > 150 || execGrade > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form &other) : name_(other.name_), isSigned_(other.isSigned_), signGrade_(other.signGrade_), execGrade_(other.execGrade_) {
	std::cout << "Form copy constructor called" << std::endl;
}

Form &Form::operator=(const Form &other) {
	std::cout << "Form assignment operator called" << std::endl;
	if (this == &other)
		return *this;
	isSigned_ = other.isSigned_;
	return *this;
}

Form::~Form() {
	std::cout << "Form destructor called" << std::endl;
}

const std::string &Form::getName() const {
	return name_;
}

bool Form::getIsSigned() const {
	return isSigned_;
}

const int &Form::getSignGrade() const {
	return signGrade_;
}

const int &Form::getExecGrade() const {
	return execGrade_;
}

void Form::beSigned(Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() > signGrade_)
		throw Form::GradeTooLowException();
	isSigned_ = true;
}

std::ostream &operator<<(std::ostream &os, const Form &form) {
	os << "Form name: " << form.getName() << std::endl;
	os << "Form sign grade: " << form.getSignGrade() << std::endl;
	os << "Form exec grade: " << form.getExecGrade() << std::endl;
	os << "Form is signed: " << form.getIsSigned() << std::endl;
	return os;
}

