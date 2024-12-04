/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuba <rmatsuba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 18:18:51 by rmatsuba          #+#    #+#             */
/*   Updated: 2024/12/04 15:56:26 by rmatsuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <stdexcept>
#include <string>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cfloat>
#include <climits>
#include <sstream>
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
	if (str.length() == 3 && str[0] == '\'' && str[str.size() - 1] == '\'')
		return Attribution(CHAR);
	try {
		/* std::stoi(str); */
		stringToInt(str);
	} catch (std::exception &e) {
		return Attribution(IMP);
	}
	if (isNanorInf(str))
		return Attribution(NANORINF);
	return Attribution(CHAR);
}

Attribution ScalarConverter::isIntConvertable(std::string &str) {
	try {
		/* std::stoi(str); */
		stringToInt(str);
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
		/* f = std::stof(str); */
		f = stringToFloat(str);
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
		/* d = std::stod(str); */
		d = stringToDouble(str);
	} catch(std::exception &e) {
		return Attribution(IMP);
	}
	if ((isnan(d) || isinf(d)) && !isNanorInf(str))
		return Attribution(IMP);
	return Attribution(DOUBLE);
}

int stringToInt(std::string &str) {
	if (!isValideNumber(str))
		throw std::invalid_argument("Invalid argument");

	std::istringstream iss(str);
	long long i;
	iss >> i;
	if (iss.fail())
		throw std::invalid_argument("Invalid argument");
	return i;
}

float stringToFloat(std::string &str) {
	float f;

	if (str == "+inf" || str == "+inff")
		return INFINITY;
	if (str == "-inf" || str == "-inff")
		return -INFINITY;
	if (!isValideNumber(str))
		throw std::invalid_argument("Invalid argument");
	std::istringstream iss(str);
	iss >> f;
	if (iss.fail())
		throw std::invalid_argument("Invalid argument");
	return f;
}

double stringToDouble(std::string &str) {
	double d;

	if (str == "+inf" || str == "+inff")
		return INFINITY;
	if (str == "-inf" || str == "-inff")
		return -INFINITY;
	if (!isValideNumber(str))
		throw std::invalid_argument("Invalid argument");
	std::istringstream iss(str);
	iss >> d;
	if (iss.fail())
		throw std::invalid_argument("Invalid argument");
	return d;
}

bool isNanorInf(std::string &str) {
	if (str == "nan" || str == "nanf" || str == "+inf" 
		|| str == "+inff" || str == "-inf" || str == "-inff")
		return true;
	return false;
}

bool isValideNumber(std::string &str) {
	if (str.empty())
		return false;
	size_t start = str.find_first_not_of(" \t");
	size_t end = str.find_last_not_of(" \t");
	std::string sub = str.substr(start, end - start + 1);
	bool isf = false;
	size_t n = sub.length();
	for (size_t i = 0; i < n; i++) {
		char c = str[i];
		/* std::cout << c << std::endl; */
		if ((c == '+' || c == '-') && (i != 0)) {
				std::cout << "plus or minus" << std::endl;
				return false;
		}
		else if (c == '.') {
			if (isf) {
				std::cout << "dot" << std::endl;
				return false;
			}
			isf = true;
		}
		else if (i == sub.size() - 1 && (c == 'f' || c == 'F')) {
			/* std::cout << "f" << std::endl; */
			return true;
		}
		else if (!isdigit(c)) {
			/* std::cout << c << std::endl; */
			return false;
		}
	}
	return true;
}

void Print(Attribution &attr, std::string &str) {
	if (attr.getAttrKind() == CHAR) {
		if (std::isprint(stringToInt(str)) && stringToInt(str) != 0)
			std::cout << "'" << static_cast<char>(stringToInt(str)) << "'" << std::endl;
		else
			std::cout << "Non displayable" << std::endl;
	}
	else if (attr.getAttrKind() == INT)
		std::cout << static_cast<int>(stringToInt(str)) << std::endl;
	else if (attr.getAttrKind() == FLOAT) {
		std::cout << std::fixed;
		std::cout << static_cast<float>(stringToFloat(str)) << 'f' << std::endl;
	}
	else if (attr.getAttrKind() == DOUBLE)
		std::cout << static_cast<double>(stringToDouble(str)) << std::endl;
	else if (attr.getAttrKind() == NANORINF)
		std::cout << "impossible" << std::endl;
	else if (attr.getAttrKind() == IMP)
		std::cout << "impossible" << std::endl;
	else if (attr.getAttrKind() == NUM)
		std::cout << "impossible" << std::endl;
}

