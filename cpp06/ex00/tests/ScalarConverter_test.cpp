#include "ScalarConverter.hpp"
#include <gtest/gtest.h>


TEST(input_test, is_valid_input) {
	EXPECT_TRUE(isValidInput("0"));
	EXPECT_TRUE(isValidInput("42"));
	EXPECT_TRUE(isValidInput("3.14"));
	EXPECT_TRUE(isValidInput("3.14f"));
	EXPECT_TRUE(isValidInput("nanf"));
	EXPECT_TRUE(isValidInput("-inff"));
	EXPECT_TRUE(isValidInput("+inff"));
	EXPECT_TRUE(isValidInput("nan"));
	EXPECT_TRUE(isValidInput("-inf"));
	EXPECT_TRUE(isValidInput("+inf"));
	EXPECT_FALSE(isValidInput("++42"));
	EXPECT_FALSE(isValidInput("--42"));
	EXPECT_FALSE(isValidInput("42.42.42"));
	EXPECT_FALSE(isValidInput("42f.42"));
	EXPECT_FALSE(isValidInput("'42.42'"));
	EXPECT_FALSE(isValidInput("42f"));
	EXPECT_FALSE(isValidInput("abcde"));
	EXPECT_FALSE(isValidInput(".f"));
	EXPECT_FALSE(isValidInput(".0f"));
	EXPECT_TRUE(isValidInput("a"));
	EXPECT_TRUE(isValidInput("+inf")); // Invalid input
	EXPECT_TRUE(isValidInput("+inff"));
	EXPECT_TRUE(isValidInput("-inf")); // Invalid input
	EXPECT_TRUE(isValidInput("-inff")); // Invalid input
	EXPECT_TRUE(isValidInput("nan")); // Invalid input
	EXPECT_TRUE(isValidInput("nanf"));
	EXPECT_FALSE(isValidInput("   ")); // Only spaces
	EXPECT_FALSE(isValidInput("3.14."));
}

TEST(input_test, trim) {
	EXPECT_EQ(trimSpaces("  42  "), "42");
	EXPECT_EQ(trimSpaces("   -42.42  "), "-42.42");
	EXPECT_EQ(trimSpaces("  3.14f  "), "3.14f");
	EXPECT_EQ(trimSpaces("  -inf  "), "-inf");
	EXPECT_EQ(trimSpaces("  +inff  "), "+inff");
	EXPECT_EQ(trimSpaces("  nan  "), "nan");
	EXPECT_EQ(trimSpaces("  -42.42f  "), "-42.42f");
	EXPECT_EQ(trimSpaces("  +42.42  "), "+42.42");
	EXPECT_EQ(trimSpaces("  0.0f  "), "0.0f");
	EXPECT_EQ(trimSpaces("  "), ""); // Only spaces
	EXPECT_EQ(trimSpaces("  'a'  "), "'a'");
	EXPECT_EQ(trimSpaces("  ' '  "), "' '"); // Single space character
	EXPECT_EQ(trimSpaces("  '42'  "), "'42'");
	EXPECT_EQ(trimSpaces("   3.14.4"), "3.14.4"); // Invalid input, but should not throw
}

TEST(input_test, is_char) {
	EXPECT_TRUE(isChar("a"));
	EXPECT_FALSE(isChar("aa"));
	EXPECT_FALSE(isChar("42"));
	EXPECT_TRUE(isChar("'a'"));
	EXPECT_FALSE(isChar("'aa'"));
	EXPECT_FALSE(isChar("'42'"));
	EXPECT_TRUE(isChar("'2'"));

}

TEST(input_test, is_int) {
	EXPECT_TRUE(isInt("42"));
	EXPECT_TRUE(isInt("-42"));
	EXPECT_TRUE(isInt("+42"));
	EXPECT_FALSE(isInt("3.14"));
	EXPECT_FALSE(isInt("3.14f"));
	EXPECT_FALSE(isInt("nan"));
	EXPECT_FALSE(isInt("inff"));
	EXPECT_FALSE(isInt("inf"));
	EXPECT_FALSE(isInt("42f.42"));
	EXPECT_FALSE(isInt("abc"));
	EXPECT_FALSE(isInt("42f"));
}

TEST(input_test, is_float) {
	EXPECT_TRUE(isFloat("3.14f"));
	EXPECT_TRUE(isFloat("-3.14f"));
	EXPECT_TRUE(isFloat("+3.14f"));
	EXPECT_FALSE(isFloat("3.14"));
	EXPECT_FALSE(isFloat("42"));
	EXPECT_FALSE(isFloat("nanf"));
	EXPECT_FALSE(isFloat("inff"));
	EXPECT_FALSE(isFloat("inf"));
	EXPECT_FALSE(isFloat("42f.42"));
}

TEST(input_test, is_double) {
	EXPECT_TRUE(isDouble("3.14"));
	EXPECT_TRUE(isDouble("-3.14"));
	EXPECT_TRUE(isDouble("+3.14"));
	EXPECT_FALSE(isDouble("3.14f"));
	EXPECT_FALSE(isDouble("42"));
	EXPECT_FALSE(isDouble("nanf"));
	EXPECT_FALSE(isDouble("inff"));
	EXPECT_FALSE(isDouble("inf"));
	EXPECT_FALSE(isDouble("42f.42"));
}

TEST(input_test, check_input_type) {
	EXPECT_EQ(checkInputType("nan"), NANN);
	EXPECT_EQ(checkInputType("nanf"), NANN);
	EXPECT_EQ(checkInputType("inf"), INF);
	EXPECT_EQ(checkInputType("inff"), INF);
	EXPECT_EQ(checkInputType("'a'"), CHAR);
	EXPECT_EQ(checkInputType("'1'"), CHAR);
	EXPECT_EQ(checkInputType("'  '"), OTHER);
}

TEST(conversion_test, str_to_char) {
	EXPECT_EQ(strToChar("a"), 'a');
	EXPECT_EQ(strToChar("b"), 'b');
	EXPECT_THROW(strToChar("ab"), std::invalid_argument);
	EXPECT_THROW(strToChar("42"), std::invalid_argument);
	// EXPECT_THROW(strToChar(" "), std::invalid_argument);
	EXPECT_EQ(strToChar(" "), ' '); // Space is a valid char
	EXPECT_THROW(strToChar(""), std::invalid_argument);
	EXPECT_EQ(strToChar("!"), '!');
	EXPECT_THROW(strToChar("1"), std::invalid_argument);
	EXPECT_THROW(strToChar("3.14"), std::invalid_argument);
}

TEST(conversion_test, str_to_int) {
	EXPECT_EQ(strToInt("42"), 42);
	EXPECT_EQ(strToInt("-42"), -42);
	EXPECT_EQ(strToInt("0"), 0);
	EXPECT_EQ(strToInt("2147483647"), 2147483647);
	EXPECT_EQ(strToInt("-2147483648"), -2147483648);
	EXPECT_THROW(strToInt("2147483648"), std::invalid_argument);
	EXPECT_THROW(strToInt("-2147483649"), std::invalid_argument);
	EXPECT_THROW(strToInt("3.14"), std::invalid_argument);
	EXPECT_THROW(strToInt("abc"), std::invalid_argument);
	EXPECT_THROW(strToInt("42f"), std::invalid_argument);
	EXPECT_THROW(strToInt("inf"), std::invalid_argument);
	EXPECT_THROW(strToInt("nan"), std::invalid_argument);
}

TEST(conversion_test, str_to_float) {
	EXPECT_FLOAT_EQ(strToFloat("3.14f"), 3.14);
	EXPECT_FLOAT_EQ(strToFloat("-3.14f"), -3.14);
	EXPECT_FLOAT_EQ(strToFloat("+3.14f"), 3.14);
	EXPECT_FLOAT_EQ(strToFloat("0.0f"), 0.0);
	EXPECT_FLOAT_EQ(strToFloat("21.0f"), 21.0);
	EXPECT_THROW(strToFloat("nan"), std::invalid_argument);
	EXPECT_THROW(strToFloat("inf"), std::invalid_argument);
	EXPECT_THROW(strToFloat("abc"), std::invalid_argument);
}

TEST(conversion_test, str_to_double) {
	EXPECT_DOUBLE_EQ(strToDouble("3.14"), 3.14);
	EXPECT_DOUBLE_EQ(strToDouble("-3.14"), -3.14);
	EXPECT_DOUBLE_EQ(strToDouble("+3.14"), 3.14);
	EXPECT_DOUBLE_EQ(strToDouble("0.0"), 0.0);
	EXPECT_DOUBLE_EQ(strToDouble("21.0"), 21.0);
	EXPECT_THROW(strToDouble("nanf"), std::invalid_argument);
	EXPECT_THROW(strToDouble("inff"), std::invalid_argument);
	EXPECT_THROW(strToDouble("abc"), std::invalid_argument);
}

TEST(print_test, print_char) {
	EXPECT_EQ(convertToChar("a", CHAR), "a");
	EXPECT_EQ(convertToChar("42", INT), "*");
	EXPECT_EQ(convertToChar("1", INT), "Non displayable");
	EXPECT_EQ(convertToChar("127", INT), "Non displayable");
	EXPECT_EQ(convertToChar("42.14f", FLOAT), "*");
	EXPECT_EQ(convertToChar("42.14", DOUBLE), "*");
	EXPECT_EQ(convertToChar("nan", NANN), "impossible");
	EXPECT_EQ(convertToChar("nanf", NANN), "impossible");
	EXPECT_EQ(convertToChar("inf", INF), "impossible");
	EXPECT_EQ(convertToChar("inff", INF), "impossible");
	EXPECT_EQ(convertToChar("'a'", CHAR), "a");
	EXPECT_EQ(convertToChar("'1'", CHAR), "1");
	EXPECT_EQ(convertToChar("' '", CHAR), "Non displayable"); // Space character
}

TEST(print_test, print_int) {
	EXPECT_EQ(convertToInt("42", INT), "42");
	EXPECT_EQ(convertToInt("3.14f", FLOAT), "3");
	EXPECT_EQ(convertToInt("0.0f", FLOAT), "0");
	EXPECT_EQ(convertToInt("0.0", FLOAT), "0");
	EXPECT_EQ(convertToInt("3.14", DOUBLE), "3");
	EXPECT_EQ(convertToInt("nan", NANN), "impossible");
	EXPECT_EQ(convertToInt("nanf", NANN), "impossible");
	EXPECT_EQ(convertToInt("inf", INF), "impossible");
	EXPECT_EQ(convertToInt("inff", INF), "impossible");
	EXPECT_EQ(convertToInt("'a'", CHAR), "97"); // ASCII value of 'a'
	EXPECT_EQ(convertToInt("'1'", CHAR), "49"); // ASCII value of '1'
}

TEST(print_test, print_float) {
	EXPECT_EQ(convertToFloat("0.0f", FLOAT), "0.000000f");
	EXPECT_EQ(convertToFloat("3.14f", FLOAT), "3.140000f");
	EXPECT_EQ(convertToFloat("3.14", DOUBLE), "3.140000f");
	EXPECT_EQ(convertToFloat("42", INT), "42.000000f");
	EXPECT_EQ(convertToFloat("nan", NANN), "nanf");
	EXPECT_EQ(convertToFloat("nanf", NANN), "nanf");
	EXPECT_EQ(convertToFloat("inff", INF), "inff");
	EXPECT_EQ(convertToFloat("inf", INF), "inff");
	EXPECT_EQ(convertToFloat("'a'", CHAR), "97.000000f"); // ASCII value of 'a'
	EXPECT_EQ(convertToFloat("'1'", CHAR), "49.000000f"); // ASCII value of '1'
}

TEST(print_test, print_double) {
	EXPECT_EQ(convertToDouble("0.0", DOUBLE), "0.000000");
	EXPECT_EQ(convertToDouble("3.14", DOUBLE), "3.140000");
	EXPECT_EQ(convertToDouble("3.14f", FLOAT), "3.140000");
	EXPECT_EQ(convertToDouble("42", INT), "42.000000");
	EXPECT_EQ(convertToDouble("nan", NANN), "nan");
	EXPECT_EQ(convertToDouble("nanf", NANN), "nan");
	EXPECT_EQ(convertToDouble("inff", INF), "inf");
	EXPECT_EQ(convertToDouble("inf", INF), "inf");
	EXPECT_EQ(convertToDouble("'a'", CHAR), "97.000000"); // ASCII value of 'a'
	EXPECT_EQ(convertToDouble("'1'", CHAR), "49.000000"); // ASCII value of '1'
}













