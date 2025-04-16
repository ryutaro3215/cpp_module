/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parse.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuba <rmatsuba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 16:29:05 by rmatsuba          #+#    #+#             */
/*   Updated: 2025/04/16 16:42:39 by rmatsuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

std::map<std::string, float> BTC::parseDatabase(std::ifstream &file) {
	std::map<std::string, float> database;
	std::string line;

	/* skip first line */
	std::getline(file, line);
	while (true) {
		std::getline(file, line);
		if (file.eof() || line.empty())
			break ;
		size_t pos = line.find(',');
		if (pos == std::string::npos)
			continue ;
		else {
			std::string date = isValidDate(line.substr(0, pos));
			float value = isValidValue(line.substr(pos + 1), false);
			if (!date.empty() && value >= 0)
				database.insert(std::make_pair(date, value));
				
		}
	}
	return database;
}

float BTC::isValidValue(const std::string &original_value, bool flag) {
	if (original_value.empty()) {
		return -1;
	}
	std::string str_value = trimSpecificChar(original_value, " \n\t");
	if (str_value.length() == 2 && str_value[0] == '-' && str_value[1] == '0')
		return -1;
	float value = convertToFloat(str_value);
	if (flag == true){
		if (value > 1000)
			return -2;
		else if (value < 0)
			return -3;
	}
	return value;
}

std::string BTC::isValidDate(const std::string &original_date) {
	if (original_date.empty()) {
		return "";
	}
	std::string date = trimSpecificChar(original_date, " \n\t");
	if (std::count(date.begin(), date.end(), '-') != 2) 
		return "";
	size_t first_dash = date.find('-');
	size_t second_dash = date.find('-', first_dash + 1);
	std::string year = date.substr(0, first_dash);
	std::string month = date.substr(first_dash + 1, second_dash - first_dash - 1);
	std::string day = date.substr(second_dash + 1);
	if (!isValidYear(year) || !isValidMonth(month) || !isValidDay(day, month)) {
		return "";
	}
	return date;
}

bool isValidYear(const std::string &year) {
	if (year.length() > 4) {
		return false;
	}
	for (size_t i = 0; i < year.length(); ++i) {
		if (isdigit(year[i]) == 0) {
			return false;
		}
		if (year[0] == '0') {
			return false;
		}
	}
	return true;
}

bool isValidMonth(const std::string &month) {
	if (month.length() > 2)
		return false;
	for (size_t i = 0; i < month.length(); ++i) {
		if (isdigit(month[i]) == 0) 
			return false;
	}
	std::istringstream iss(month);
	int month_num;
	iss >> month_num;
	if (month_num < 1 || month_num > 12) {
		return false;
	}
	return true;
}

bool isValidDay(const std::string &day, const std::string &month) {
	if (day.length() > 2)
		return false;
	std::istringstream miss(month);
	int month_num;
	miss >> month_num;
	for (size_t i = 0; i < day.length(); ++i) {
		if (isdigit(day[i]) == 0)
			return false;
	}
	std::istringstream diss(day);
	int day_num;
	diss >> day_num;
	if (day_num < 1 || day_num > 31)
		return false;
	if ((month_num == 2 || month_num == 4 || month_num == 6 || month_num == 9 || month_num == 11) && day_num == 31)
		return false;
	return true;
}

std::string trimSpecificChar(const std::string str, const char* chars) {
	if (str.empty()) {
		return str;
	}
	std::string result = str;
	size_t start = result.find_first_not_of(chars);
	if (start == std::string::npos) {
		return "";
	}
	result.erase(0, start);
	size_t end = result.find_last_not_of(chars);
	result.erase(end + 1);
	return result;
}

float convertToFloat(const std::string &str) {
	std::istringstream iss(str);
	float value;
	iss >> value;
	if (iss.fail() || !iss.eof()) {
		throw std::invalid_argument("Invalid float value");
	}
	return value;
}
