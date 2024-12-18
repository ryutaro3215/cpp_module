/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuba <rmatsuba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 14:00:00 by rmatsuba          #+#    #+#             */
/*   Updated: 2024/11/27 18:26:24 by rmatsuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"
# include <iostream>

class Intern {
	public:
		Intern();
		Intern(const Intern &other);
		~Intern();
		Intern &operator=(const Intern &other);
		AForm *makeForm(std::string name, std::string target);
		static AForm *makePresidentialPardonForm(const std::string &target);
		static AForm *makeRobotomyRequestForm(const std::string &target);
		static AForm *makeShrubberyCreationForm(const std::string &target);
};

#endif
