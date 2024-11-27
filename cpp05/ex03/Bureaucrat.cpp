/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuba <rmatsuba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 01:08:12 by rmatsuba          #+#    #+#             */
/*   Updated: 2024/11/27 18:08:58 by rmatsuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/Bureaucrat.hpp"
#include "./includes/AForm.hpp"

/* overload of std::exception::what */
const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade is too high!!";
}

/* overload of std::exception::what */
const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade is too low!!";
}

/* this is default constructor of Bureaucrat */
Bureaucrat::Bureaucrat() : name_("default"), grade_(150) {}

/* This is the constructor of Bureaucrat */
Bureaucrat::Bureaucrat(std::string name, int grade) : name_(name), grade_(grade) {
	if (grade_ < 1)
		throw GradeTooHighException();
	else if (grade_ > 150)
		throw GradeTooLowException();
}

/* destructor of Bureaucrat */
Bureaucrat::~Bureaucrat() {}

/* copy constructor of Bureaucrat */
Bureaucrat::Bureaucrat(const Bureaucrat &other) : name_(other.name_), grade_(other.grade_) {}

/* assignment operator of Bureaucrat */
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
	if (this == &other)
		return *this;
	grade_ = other.grade_;
	return *this;
}

/* name getter of Bureaucrat */
const std::string &Bureaucrat::getName() const {
	return name_;
}

/* grade getter of Bureaucrat */ 
int Bureaucrat::getGrade() const {
	return grade_;
}

/* upgrade the grade of Bureaucrat */
void Bureaucrat::upGrade() {
	if (grade_ - 1 < 1)
		throw GradeTooHighException();
	grade_--;
}

/* downgrade the grade of Bureaucrat */
void Bureaucrat::downGrade() {
	if (grade_ + 1 > 150) {
		throw GradeTooLowException();
	}
	grade_++;
}

void Bureaucrat::signForm(AForm &form) {
	if (form.getIsSigned() == true)
		std::cout << getName() << "cannot sign, " << " because " << 
			form.getName() << " is already signed"	<< std::endl;
	try {
		form.beSigned(*this);
	} catch (AForm::GradeTooLowException &e) {
		std::cout << getName() << "cannot sign, " << "because " << 
			getName() << "'s grade is too Low";
		return ;
	}
	std::cout << getName() << " signed " << form.getName() << std::endl;
}

void Bureaucrat::executeForm(AForm const &form) {
	try {
		std::cout << getName() << " executes " << form.getName() << std::endl;
		form.execute(*this);
	} catch (AForm::isNotsignedException &e) {
		std::cerr << getName() << " cannot execute " << form.getName() << " because it is not signed" << std::endl;
	} catch (AForm::GradeTooLowException &e) {
		std::cerr << getName() << " cannot execute " << form.getName() << " because " << getName() << "'s grade is too low" << std::endl;
	} 
}

/* overload of << operator */
std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat) {
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return os;
}

