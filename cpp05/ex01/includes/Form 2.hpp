/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuba <rmatsuba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:37:51 by rmatsuba          #+#    #+#             */
/*   Updated: 2024/11/27 17:53:09 by rmatsuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>

class Bureaucrat;

class Form {
	private:
		const std::string name_;
		bool isSigned_;
		const int signGrade_;
		const int execGrade_;
		Form();
	public:
		Form(const std::string name, const int signGrade, const int execGrade);
		Form(const Form &other);
		Form &operator=(const Form &other);
		~Form();
		const std::string &getName() const;
		bool getIsSigned() const;
		const int &getSignGrade() const;
		const int &getExecGrade() const;
		void beSigned(Bureaucrat const &bureaucrat);
		class GradeTooHighException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &os, const Form &form);

#endif
