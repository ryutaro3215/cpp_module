#include "BitcoinExchange.hpp"

void printBitcoinAmount(std::string input_path, std::map<std::string, float>& price_data) {
	std::ifstream file(input_path);
	std::string line;
	std::string output_line;

	if (!file)
		throw std::exception();
	getline(file, line);
	while (getline(file, line)) {
		if (file.bad())
			throw std::exception();
		size_t separation = line.find("|");
		if (separation == std::string::npos || line[separation - 1] != ' ' || line[separation + 1] != ' ') {
			output_line =  "Error: bad input -> " + line;
		} else {
			std::string date = line.substr(0, separation);
			std::string amount = line.substr(separation + 1);
			output_line = calcBitcoinVal(date, amount, price_data);
		}
		std::cout << output_line << std::endl;
	}
}

std::string calcBitcoinVal(std::string date, std::string amount, std::map<std::string, float>& price_data) {
	std::string trimed_date = checkDate(trimSpace(date));
	if (trimed_date.rfind("Error", 0) == 0)
		return trimed_date;
	std::string trimed_amount = checkAmount(trimSpace(amount));
	if (trimed_amount != trimSpace(amount))
		return trimed_amount;
	float rate = getRate(date, price_data);
	float total_value = rate * strToT<float>(amount);
	std::stringstream sstream;
	sstream << total_value;
	std::string str_total_value = sstream.str();
	return trimed_date + " => " + trimed_amount + " = " + str_total_value;
}

float getRate(std::string date, std::map<std::string, float>& price_data) {
	float prev_price = 0;
	for (std::map<std::string, float>::iterator it = price_data.begin(); it != price_data.end(); it++) {
		if (date.compare(it->first) == 0)
			return it->second;
		else if (date.compare(it->first) > 0)
				prev_price = it->second;
		else 
			return prev_price;
	}
	return prev_price;
}


std::string checkAmount(std::string amount) {
	int point_count = 0;
	for (size_t i = 0; i < amount.length(); i++) {
		if ((amount[i] == '+' || amount[i] == '-') && i == 0)
			continue;
		else if (amount[i] == '.' && point_count == 0)
			point_count++;
		else if (!isdigit(amount[i]))
			return "Error: not a number";
	}
	float float_amount = strToT<float>(amount);
	if (float_amount < 0)
		return "Error: not a positive number";
	if (float_amount > 1000)
		return "Error: too large a number";
	return amount;
}

std::string checkDate(std::string date) {
	size_t first = date.find("-");
	size_t second = date.find("-", first + 1);
	if (first == std::string::npos || second == std::string::npos)
		return "Error: Bad input -> " + date;
	std::string year = date.substr(0, first);
	std::string month = date.substr(first + 1, second - first - 1);
	std::string day = date.substr(second + 1);
	if (!checkYear(year) || !checkMonth(month) || !checkDay(day, month, year))
		return "Error: Bad input -> " + date;
	return date;
}

bool checkYear(std::string year) {
	size_t zero_count = 0;
	for (size_t i = 0; i < year.length(); i++) {
		char c = year[i];
		if (!isdigit(c))
			return false;
		if (c == '0')
			zero_count++;
	}
	if (zero_count == year.size())
		return false;
	return true;
}

bool checkMonth(std::string month) {
	std::string month_data[] = {"01", "02", "03", "04", "05", "06",
		"07", "08", "09", "10", "11", "12"};
	for (size_t i = 0; i < sizeof(month_data) / sizeof(std::string); i++) {
		if (month == month_data[i])
			return true;
	}
	return false;
}

bool checkDay(std::string day, std::string month, std::string year) {
	// check whether digit
	for (size_t i = 0; i < day.length(); i++) {
		if (!isdigit(day[i]))
			return false;
	}

	bool flag = true;
	int int_year = strToT<int>(year);
	int int_month = strToT<int>(month);
	int int_day = strToT<int>(day);
	bool is_leap = isLeapYear(int_year);
	if (int_month == 2) {
		if (is_leap && (int_day > 29 || int_day < 1))
			flag = false;
		else if (!is_leap && (int_day > 28 || int_day < 1))
			flag = false;
	} else if (int_month == 4 || int_month == 6 || int_month == 9 || int_month == 11) {
		if (int_day > 30 || int_day < 1)
			flag = false;
	} else if (int_month == 1 || int_month == 3 || int_month == 5 || int_month == 7 || int_month == 8
			|| int_month == 10 || int_month == 12) {
		if (int_day > 31 || int_day < 1)
			flag = false;
	}
	return flag;
}

template<typename T>
T strToT(std::string input) {
	std::istringstream iss(input);
	T it;

	iss >> it;
	return it;
}

bool isLeapYear(int y) {
	if (y % 4 == 0 && y % 100 == 0) {
		if (y % 400 == 0)
			return true;
		else
			return false;
	} else if (y % 4 == 0) {
			return true;
	} else
			return false;
}

std::string trimSpace(std::string str) {
	if (str.empty())
		return "";
	size_t first = 0;
	size_t last = str.size();
	while (first < str.size() && std::isspace(static_cast<unsigned char>(str[first])))
		++first;
	while (last > first && std::isspace(static_cast<unsigned char>(str[last - 1])))
		--last;

	return str.substr(first, last - first);
}


std::map<std::string, float> read_date_csv() {
	std::ifstream file("data.csv");
	std::map<std::string, float> data;
	std::string line;

	//skip first line
	getline(file, line);
	while (getline(file, line)) {
		if (file.bad())
			throw std::exception();
		size_t comma = line.find(",");
		const std::string date = line.substr(0, comma);
		std::string price_str = line.substr(comma + 1);
		float price = strToFloat(price_str);
		data.insert(std::make_pair(date, price));
	}
	return data;
}

float strToFloat(std::string str) {
	if (str.empty())
		throw std::exception();
	std::istringstream iss(str);
	float f;
	iss >> f;
	if (iss.fail())
		throw std::exception();
	return f;
}

