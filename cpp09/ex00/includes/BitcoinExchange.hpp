#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <map>
#include <sstream>
#include <algorithm>


class BTC {
	private:
		std::map<std::string, float> _database;
	public:
		BTC();
		~BTC();
		BTC(const BTC &src);
		BTC &operator=(const BTC &src);
		void executeExchange(const std::string &filename);
		std::map<std::string, float> parseDatabase(std::ifstream &file);
		std::string isValidDate(const std::string &original_date);
		float isValidValue(const std::string &original_value, bool flag);
};

std::string trimSpecificChar(const std::string str, const char* chars);
float convertToFloat(const std::string &str);
bool isValidYear(const std::string &year);
bool isValidMonth(const std::string &month);
bool isValidDay(const std::string &day, const std::string &month);



#endif
