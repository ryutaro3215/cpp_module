/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuba <rmatsuba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 01:08:12 by rmatsuba          #+#    #+#             */
/*   Updated: 2024/10/28 15:53:48 by rmatsuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/Bureaucrat.hpp"
#include "./includes/Form.hpp"

/* overload of std::exception::what */
const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade is too high!!";
}

/* overload of std::exception::what */
const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade is too low!!";
}

/* this is default constructor of Bureaucrat */
Bureaucrat::Bureaucrat() : name_("default"), grade_(150) {
	std::cout << "Bureaucrat default constructor called" << std::endl;
}

/* This is the constructor of Bureaucrat */
Bureaucrat::Bureaucrat(std::string name, int grade) : name_(name), grade_(grade) {
	std::cout << "Bureaucrat constructor called" << std::endl;
	if (grade_ < 1)
		throw GradeTooHighException();
	else if (grade_ > 150)
		throw GradeTooLowException();
}

/* destructor of Bureaucrat */
Bureaucrat::~Bureaucrat() {
	std::cout << "Bureaucrat destructor called" << std::endl;
}

/* copy constructor of Bureaucrat */
Bureaucrat::Bureaucrat(const Bureaucrat &other) : name_(other.name_), grade_(other.grade_) {
	std::cout << "Bureaucrat copy constructor called" << std::endl;
}

/* assignment operator of Bureaucrat */
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
	std::cout << "Bureaucrat assignment operator called" << std::endl;
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

void Bureaucrat::signForm(Form &form) {
	if (form.getIsSigned() == true)
		std::cout << this->getName() << " signed " << form.getName() << std::endl;
	else
		std::cout << "Bureaucrat " << this->getName() << " couldn't sign " << form.getName() << " because " <<
			this->getName() << "'s grade is too low." << std::endl;
}

/* overload of << operator */
std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat) {
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return os;
}

