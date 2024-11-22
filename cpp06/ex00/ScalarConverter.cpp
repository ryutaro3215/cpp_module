/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuba <rmatsuba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 18:18:51 by rmatsuba          #+#    #+#             */
/*   Updated: 2024/11/22 20:02:48 by rmatsuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ScalarConverter.hpp"
#include <string>

ScalarConverter::ScalarConverter(std::string &str) {
	m_data.c = static_cast<char>(str);
	m_data.i = static_cast<int>(str);
	m_data.f = static_cast<float>(str);
	m_data.d = static_cast<double>(str);
}

ScalarConverter::~ScalarConverter() {
}

void ScalarConverter::convert(const std::string &str) {
	ScalarConverter result(str);

	std::cout << "Input: " << str << std::endl;
	result.printChar(result.m_data);
	result.printInt(result.m_data);
	result.printFloat(result.m_data);
	result.printDouble(result.m_data);
}

/* void ScalarConverter::isChar(const std::string &str) { */
/* 	char c = stoi(str); */
/* 	if (c < '!' || c > '~') */
/* 		throw std::invalid_argument("Error: Invalid char"); */
/* 	m_data.c = c; */
/* } */

void ScalarConverter::printChar(const s_data &data) {
	try {
		m_data.c = 
	}
	std::cout << "char: " << data.c << std::endl;
}
void ScalarConverter::printInt(const s_data &data) {
	std::cout << "Int: " << data.i << std::endl;
}
void ScalarConverter::printFloat(const s_data &data) {
	std::cout << "Float: " << data.f << std::endl;
}
void ScalarConverter::printDouble(const s_data &data) {
	std::cout << "Double: " << data.d << std::endl;
}
