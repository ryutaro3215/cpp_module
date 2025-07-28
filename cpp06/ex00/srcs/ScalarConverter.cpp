#include "ScalarConverter.hpp"


ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &other) {
	*this = other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) {
	if (this != &other)
		*this = other;
	return *this;
}

ScalarConverter::~ScalarConverter() {}


void ScalarConverter::convert(const char *input) {
	// Convert the input string to a 
	std::string trimmedInput = trimSpaces(input);
	if (!isValidInput(trimmedInput)) {
		std::cout << "Invalid input" << std::endl;
		std::cout << "Please enter a valid input, char literal or number literal." << std::endl;
		return;
	}
	int type = checkInputType(trimmedInput);
	std::cout << "Char: " << convertToChar(trimmedInput, type) << std::endl;
	std::cout << "Int: " << convertToInt(trimmedInput, type) << std::endl;
	std::cout << "Float: " << convertToFloat(trimmedInput, type) << std::endl;
	std::cout << "Double: " << convertToDouble(trimmedInput, type) << std::endl;
}

std::string convertToChar(const std::string &input, int type) {
	if (type == NANN || type == INF || type == OTHER) {
		return "impossible";
	} else if (type == CHAR) 
		try {
			char c = strToChar(input);
			if (isprint(c) && c >= 33 && c <= 126)
				return std::string(1, c);
			else
				return "Non displayable";
		} catch (const std::invalid_argument &e) {
			return "impossible";
		}
	else if (type == INT) {
		try {
			char c = static_cast<char>(strToInt(input));
			if (isprint(c))
				return std::string(1, c);
			else
				return "Non displayable";
		} catch (const std::invalid_argument &e) {
			return "impossible";
		}
	} else if (type == FLOAT || type == DOUBLE) {
		try {
			char c = static_cast<char>(strToFloat(input));
			if (isprint(c))
				return std::string(1, c);
			else
				return "Non displayable";
		} catch (const std::invalid_argument &e) {
			return "impossible";
		}
	} else {
		return "impossible"; // For INF or NANN
	}
}

std::string convertToInt(const std::string &input, int type) {
	if (type == NANN || type == INF || type == OTHER)
		return "impossible";
	else if (type == CHAR) {
		return toString(static_cast<int>(strToChar(input)));
	} else if (type == INT) {
		try {
			return toString(strToInt(input));
		} catch (const std::invalid_argument &e) {
			return "impossible";
		}
	} else if (type == FLOAT) {
		try {
				return toString(static_cast<int>(strToFloat(input)));
		} catch (const std::invalid_argument &e) { 
			return "impossible";
		}
	} else if (type == DOUBLE) {
		try {
			return toString(static_cast<int>(strToDouble(input)));
		} catch (const std::invalid_argument &e) {
			return "impossible";
		}
	} else {
		return "impossible"; // For INF or NANN
	}
}

std::string convertToFloat(const std::string &input, int value) {
	if (isNan(input)) 
		return "nanf";
	else if (input == "inf" || input == "+inf" || input == "inff" || input == "+inff")
		return "inff";
	else if (input == "-inf" || input == "-inff")
			return "-inff";
	else if (value == CHAR) {
		try {
			return toString(static_cast<float>(strToChar(input))) + "f";
		} catch (const std::invalid_argument &e) {
			return "impossible";
		}
	} else if (value == INT) {
		try {
			return toString(static_cast<float>(strToInt(input))) + "f";
		} catch (const std::invalid_argument &e) {
			return "impossible";
		}
	} else if (value == FLOAT) {
		try {
			return toString(strToFloat(input)) + "f";
		} catch (const std::invalid_argument &e) {
			return "impossible";
		}
	} else if (value == DOUBLE) {
		try {
			return toString(static_cast<float>(strToDouble(input))) + "f";
		} catch (const std::invalid_argument &e) {
			return "impossible";
		}
	} else {
		return "impossible"; // For INF or NANN
	}
}

std::string convertToDouble(const std::string &input, int value) {
	if (isNan(input))
		return "nan";
	else if (input == "inf" || input == "+inf" || input == "+inff" || input == "inff")
		return "inf";
	else if (input == "-inf" || input == "-inff")
			return "-inf";
	else if (value == CHAR) {
		try {
			return toString(static_cast<double>(strToChar(input)));
		} catch (const std::invalid_argument &e) {
			return "impossible";
		}
	} else if (value == INT) {
		try {
			return toString(static_cast<double>(strToInt(input)));
		} catch (const std::invalid_argument &e) {
			return "impossible";
		}
	} else if (value == FLOAT) {
		try {
			return toString(static_cast<double>(strToFloat(input)));
		} catch (const std::invalid_argument &e) {
			return "impossible";
		}
	} else if (value == DOUBLE) {
		try {
			return toString(strToDouble(input));
		} catch (const std::invalid_argument &e) {
			return "impossible";
		}
	} else {
		return "impossible"; // For INF or NANN
	}
}


int checkInputType(const std::string &input) {
	if (isNan(input))
		return NANN;
	else if (isInf(input))
		return INF;
	else if (isChar(input))
		return CHAR;
	else if (isFloat(input))
		return FLOAT;
	else if (isDouble(input))
		return DOUBLE;
	else if (isInt(input))
		return INT;
	return OTHER; // Default case
}

//Check the input is valid for conversion
bool isValidInput(const std::string &input) {
	// Trim spaces and check whether the input is empty
	int pointCount = 0;
	if (input.empty())
		return false; // Empty input after trimming
	if (isNan(input) || isInf(input))
		return true;
	if (isChar(input))
		return true;
	for (size_t i = 0; i < input.length(); ++i) {
		char c = input[i];
		if ((c == '-' || c == '+') && i == 0) 
			continue;
		else if (c == 'f' && i == input.length() - 1 && pointCount == 1)
			continue;
		else if (c == '.') {
			if (++pointCount > 1)
				return false;
			if (i == 0 || i == input.length() - 1)
				return false; // '.' cannot be at the start or end
		}
		else if (!isdigit(c))
			return false;
	}
	return true;
}

bool isNan(const std::string &input) {
	if (input == "nan" || input == "nanf") {
		return true;
	}
	return false;
}

bool isInf(const std::string &input) {
	if (input == "inf" || input == "+inf" || input == "-inf" ||
		input == "inff" || input == "+inff" || input == "-inff") {
		return true;
	}
	return false;
}

bool isChar(const std::string &input) {
	// if (input.length() == 1 && isprint(input[0]) && !isdigit(input[0]))
	// 	return true; 
	if (input.length() == 3 && input[0] == '\'' && input[2] == '\'' && isprint(input[1])) {
		return true; // Handle single character with quotes
	}
	return false;
}

bool isInt(const std::string &input) {
	for (size_t i = 0; i < input.length(); ++i) {
		if ((input[i] == '-' || input[i] == '+') && i == 0)
			continue; // Allow leading sign
		if (!isdigit(input[i]))
			return false; // Non-digit character found
	}
	return true;
}

bool isFloat(const std::string &input) {
	bool hasPoint = false;
	bool hasF = false;
	for (size_t i = 0; i < input.length(); ++i) {
		if (input[i] == '.')
			hasPoint = true;
		if (input[i] == 'f' && i == input.length() - 1) {
			hasF = true;
		}
	}
	if (hasF && hasPoint) {
		return true;
	}
	return false;
}

bool isDouble(const std::string &input) {
	bool hasPoint = false;
	for (size_t i = 0; i < input.length(); ++i) {
		if (input[i] == '.') {
			hasPoint = true;
			break;
		}
	}
	if (hasPoint && input.find('f') == std::string::npos) {
		return true;
	}
	return false;
}

char strToChar(const std::string &input) {
	if (input.length() == 1 && isprint(input[0]) && !isdigit(input[0]))
		return input[0]; // Single printable character
	else if (input.length() == 3 && input[0] == '\'' && input[2] == '\'' && isprint(input[1]))
		return input[1]; // Single character with quotes
	else
		throw std::invalid_argument("Invalid character conversion");
}

int strToInt(const std::string &input) {
	int i;
	std::istringstream iss(input);
	iss >> i;
	if (iss.fail() || !iss.eof())
		throw std::invalid_argument("Invalid integer conversion");
	return i;
}

float strToFloat(const std::string &input) {
	std::string trimf = input.substr(0, input.length() - 1);
	float f;
	std::istringstream iss(trimf);
	iss >> f;
	if (iss.fail() || !iss.eof())
		throw std::invalid_argument("invalid float conversion");
	return f;
}

double strToDouble(const std::string &input) {
	double d;
	std::istringstream iss(input);
	iss >> d;
	if (iss.fail() || !iss.eof())
		throw std::invalid_argument("Invalid double conversion");
	return d;
}

std::string trimSpaces(const std::string &input) {
	size_t start = input.find_first_not_of(" \t\n\r\f\v");
	size_t end = input.find_last_not_of(" \t\n\r\f\v");
	if (start == std::string::npos || end == std::string::npos) {
		return ""; // Return empty string if only spaces
	}
	return input.substr(start, end - start + 1);
}

template <typename T>
std::string toString(T value) {
	std::ostringstream oss;
	if (value == static_cast<long>(value))
		oss << std::fixed << std::setprecision(1); // Ensure one decimal place for float
	oss << value;
	return oss.str();
}









