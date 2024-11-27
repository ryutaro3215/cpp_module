/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuba <rmatsuba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 17:12:53 by rmatsuba          #+#    #+#             */
/*   Updated: 2024/11/26 10:41:13 by rmatsuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include "Attribution.hpp"
#include <string>

typedef struct isConvertable {
	Attribution charConvertable;
	Attribution intConvertable;
	Attribution floatConvertable;
	Attribution doubleConvertable;
} ConvertableCheck;

class ScalarConverter {
	private:
		ConvertableCheck *m_checker;
		ScalarConverter(std::string str);
		~ScalarConverter();
		ScalarConverter(const ScalarConverter &other);
		ScalarConverter &operator=(const ScalarConverter &other);
		ConvertableCheck* checkConvertable(std::string &str);
		Attribution isCharConvertable(std::string &str);
		Attribution isIntConvertable(std::string &str);
		Attribution isFloatConvertable(std::string &str);
		Attribution isDoubleConvertable(std::string &str);
	public:
		static void convert(std::string str);
};

bool isNanorInf(std::string &str);
void Print(Attribution &attr, std::string &str);
#endif

