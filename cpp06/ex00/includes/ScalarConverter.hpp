/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuba <rmatsuba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 17:12:53 by rmatsuba          #+#    #+#             */
/*   Updated: 2024/11/22 20:03:05 by rmatsuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>

struct s_data
{
	char c;
	int i;
	float f;
	double d;
}; 

class ScalarConverter
{
	private:
		s_data m_data;
		ScalarConverter(std::string &str);
		~ScalarConverter();
		void isChar(const std::string &str);
		void isInt(const std::string &str);
		void isFloat(const std::string &str);
		void isDouble(const std::string &str);
		void printChar(const s_data &data); 
		void printInt(const s_data &data);
		void printFloat(const s_data &data);
		void printDouble(const s_data &data);
		/* class InvalidChar : public std::exception { */
		/* 	public: */
		/* 		virtual const char* what() const thorw() { */
		/* 			return "Non displayable"; */
		/* 		} */
		/* } */
	public:
		static void convert(const std::string &str);
};

#endif

