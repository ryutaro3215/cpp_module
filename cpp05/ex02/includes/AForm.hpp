/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuba <rmatsuba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:37:51 by rmatsuba          #+#    #+#             */
/*   Updated: 2024/10/31 15:18:25 by rmatsuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>

class Bureaucrat;

class AForm {
	private:
		const std::string name_;
		bool isSigned_;
		const int signGrade_;
		const int execGrade_;
	protected:
		std::string target_;
	public:
		AForm();
		AForm(const std::string name, const int signGrade, const int execGrade);
		AForm(const AForm &other);
		AForm &operator=(const AForm &other);
		virtual ~AForm();
		const std::string &getName() const;
		bool getIsSigned() const;
		const int &getSignGrade() const;
		const int &getExecGrade() const;
		virtual void execute(Bureaucrat const &executor) const = 0;
		void beSigned(Bureaucrat &bureaucrat);
		class GradeTooHighException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
		class isNotsignedException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &os, const AForm &form);

#endif
