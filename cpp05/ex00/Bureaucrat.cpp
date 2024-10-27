/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuba <rmatsuba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 17:06:30 by rmatsuba          #+#    #+#             */
/*   Updated: 2024/10/27 18:06:36 by rmatsuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name_("default"), grade_(75) {
	std::cout << "Bureaucrat default constructor called" << std::endl;
} 

Bureaucrat::Bureaucrat(std::string name, int grade) : name_(name) grade_(grade) {
	std::cout << "Bureaucrat constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Bureaucrat destructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) {
	name_ = other.getName();
	grade_ = other.getGrade();
	std::cout << "Bureaucrat copy constructor called" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
	if (this == &other)
		return *this;
	name_ = other.getName();
	grade_ = other.getGrade();
	std::cout << "Bureaucrat assignation operator called" << std::endl;
	return *this;
}
