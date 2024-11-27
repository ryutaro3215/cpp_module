/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuba <rmatsuba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 18:18:51 by rmatsuba          #+#    #+#             */
/*   Updated: 2024/11/27 16:00:37 by rmatsuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "./includes/ScalarConverter.hpp"
#include <iomanip>

ScalarConverter::ScalarConverter(std::string str) 
	: m_checker(checkConvertable(str)) {};

ScalarConverter::~ScalarConverter() {
	delete m_checker;
};

ScalarConverter::ScalarConverter(const ScalarConverter &other) {
	*this = other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) {
	if (this == &other)
		return *this;
	return *this;
}

void ScalarConverter::convert(std::string str) {
	ScalarConverter *converter = new ScalarConverter(str);
	std::cout << "char: ";
	Print(converter->m_checker->charConvertable, str);
	std::cout << "Int: ";
	Print(converter->m_checker->intConvertable, str);
	std::cout << "float: ";
	Print(converter->m_checker->floatConvertable, str);
	std::cout << "double: ";
	Print(converter->m_checker->doubleConvertable, str);
}

ConvertableCheck* ScalarConverter::checkConvertable(std::string &str) {
	ConvertableCheck *checker = new ConvertableCheck;
	checker->charConvertable = isCharConvertable(str);
	checker->intConvertable = isIntConvertable(str);
	checker->floatConvertable = isFloatConvertable(str);
	checker->doubleConvertable = isDoubleConvertable(str);
	return checker;
}

Attribution ScalarConverter::isCharConvertable(std::string &str) {
	if (str.length() == 3 && str.front() == '\'' && str.back() == '\'')
		return Attribution(CHAR);
	try {
		std::stoi(str);
	} catch (std::exception &e) {
		return Attribution(IMP);
	}
	if (isNanorInf(str))
		return Attribution(NANORINF);
	return Attribution(CHAR);
}

Attribution ScalarConverter::isIntConvertable(std::string &str) {
	try {
		std::stoi(str);
	} catch (std::exception &e) {
		return Attribution(IMP);
	}
	/* if (str.find('.') != std::string::npos) */
	/* 	return Attribution(FLOAT); */
	return Attribution(INT);
}

Attribution ScalarConverter::isFloatConvertable(std::string &str) {
	float f;
	try {
		f = std::stof(str);
	} catch (std::exception &e) {
		return Attribution(IMP);
	}
	if ((isnan(f) || isinf(f)) && !isNanorInf(str))
		return Attribution(IMP);
	return Attribution(FLOAT);
}

Attribution ScalarConverter::isDoubleConvertable(std::string &str) {
	double d;
	try {
		d = std::stod(str);
	} catch(std::exception &e) {
		return Attribution(IMP);
	}
	if ((isnan(d) || isinf(d)) && !isNanorInf(str))
		return Attribution(IMP);
	return Attribution(DOUBLE);
}

bool isNanorInf(std::string &str) {
	if (str == "nan" || str == "nanf" || str == "+inf" 
		|| str == "+inff" || str == "-inf" || str == "-inff")
		return true;
	return false;
}

void Print(Attribution &attr, std::string &str) {
	if (attr.getAttrKind() == CHAR) {
		if (std::isprint(std::stoi(str)) && std::stoi(str) != 0)
			std::cout << "'" << static_cast<char>(std::stoi(str)) << "'" << std::endl;
		else
			std::cout << "Non displayable" << std::endl;
	}
	else if (attr.getAttrKind() == INT)
		std::cout << static_cast<int>(std::stoi(str)) << std::endl;
	else if (attr.getAttrKind() == FLOAT) {
		std::cout << std::fixed << std::setprecision(1);
		std::cout << static_cast<float>(std::stof(str)) << 'f' << std::endl;
	}
	else if (attr.getAttrKind() == DOUBLE)
		std::cout << static_cast<double>(std::stod(str)) << std::endl;
	else if (attr.getAttrKind() == NANORINF)
		std::cout << "impossible" << std::endl;
	else if (attr.getAttrKind() == IMP)
		std::cout << "impossible" << std::endl;
	else if (attr.getAttrKind() == NUM)
		std::cout << "impossible" << std::endl;
}

