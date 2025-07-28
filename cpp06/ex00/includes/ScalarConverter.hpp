#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>


enum ConversionType {
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	INF,
	NANN,
	OTHER
};

class ScalarConverter
{
private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &other);
		ScalarConverter &operator=(const ScalarConverter &other);
		~ScalarConverter();
public:
		static void convert(const char *input);
};

bool isValidInput(const std::string &input);
std::string trimSpaces(const std::string &input);
bool isNan(const std::string &input);
bool isInf(const std::string &input);
bool isChar(const std::string &input);
bool isInt(const std::string &input);
bool isFloat(const std::string &input);
bool isDouble(const std::string &input);
int checkInputType(const std::string &input);
char strToChar(const std::string &input);
int strToInt(const std::string &input);
float strToFloat(const std::string &input);
double strToDouble(const std::string &input);
std::string convertToChar(const std::string &input, int type);
std::string convertToInt(const std::string &input, int type);
std::string convertToFloat(const std::string &input, int type);
std::string convertToDouble(const std::string &input, int type);
template <typename T>
std::string toString(T value);

#endif
