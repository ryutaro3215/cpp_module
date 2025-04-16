/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuba <rmatsuba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 16:30:32 by rmatsuba          #+#    #+#             */
/*   Updated: 2025/04/16 16:39:24 by rmatsuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

#include "includes/BitcoinExchange.hpp"
#include <iostream>
#include <sstream>
#include <string>

BTC::BTC() {}

BTC::~BTC() {}

BTC::BTC(const BTC &src) {
	*this = src;
}

BTC &BTC::operator=(const BTC &src) {
	if (this != &src) {
		this->_database = src._database;
	}
	return *this;
}

void BTC::executeExchange(const std::string &filename) {
	std::ifstream file(filename);
	if (!file.is_open()) {
		std::cerr << "Error: could not open file " << filename << std::endl;
		return;
	}
	std::ifstream db_file("data.csv");
	if (!db_file.is_open()) {
		std::cerr << "Error: could not open database file data.csv" << std::endl;
		return;
	}
	_database = parseDatabase(db_file);
	std::string line;
	std::getline(file, line);
	while (true) {
		std::getline(file, line);
		if (file.eof() || line.empty())
			break ;
		size_t pos = line.find('|');
		if (pos == std::string::npos) {
			std::cout << "Error: bad input => " << line << std::endl;
			continue ;
		} else {
			std::string date = isValidDate(line.substr(0, pos));
			float value = isValidValue(line.substr(pos + 1), true);
			if (date.empty() || value == -1) {
				std::cout << "Error: bad input => " << line << std::endl;
				continue ;
			} else if (value == -2)
				std::cout << "Error: too large a number." << std::endl;
			else if (value == -3)
				std::cout << "Error: not a positive number." << std::endl;
			else {
				std::map<std::string, float>::iterator it = _database.lower_bound(date);
				std::cout << date << " => " << value << " = " << value * it->second << std::endl;
			}
		}
	}
}
