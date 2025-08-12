#include <gtest/gtest.h>
#include "BitcoinExchange.hpp"

TEST(BitcoinExchange, strToFloat) {
	EXPECT_THROW(strToFloat(""), std::exception);
	EXPECT_FLOAT_EQ(123.0f, strToFloat("123"));
	EXPECT_FLOAT_EQ(123.456f, strToFloat("123.456"));
}

TEST(BitcoinExchange, trimSpace) {
		EXPECT_EQ(trimSpace(" 2002-05-15  "), "2002-05-15");
    EXPECT_EQ(trimSpace("\t 2002-05-15\n"), "2002-05-15"); // タブや改行もOK
    EXPECT_EQ(trimSpace("no_space"), "no_space");
    EXPECT_EQ(trimSpace("     "), ""); // 空白だけの場合
}

TEST(BitcoinExchange, checkdate) {
	//Year Test
	EXPECT_TRUE(checkYear("2024"));
	EXPECT_TRUE(checkYear("1024"));
	EXPECT_FALSE(checkYear(" 2024 "));
	EXPECT_FALSE(checkYear("-1024"));
	//Month Test
	EXPECT_TRUE(checkMonth("01"));
	EXPECT_TRUE(checkMonth("02"));
	EXPECT_TRUE(checkMonth("03"));
	EXPECT_TRUE(checkMonth("04"));
	EXPECT_TRUE(checkMonth("05"));
	EXPECT_TRUE(checkMonth("06"));
	EXPECT_TRUE(checkMonth("07"));
	EXPECT_TRUE(checkMonth("08"));
	EXPECT_TRUE(checkMonth("09"));
	EXPECT_TRUE(checkMonth("10"));
	EXPECT_TRUE(checkMonth("11"));
	EXPECT_TRUE(checkMonth("12"));
	EXPECT_FALSE(checkMonth(" 12"));
	EXPECT_FALSE(checkMonth(" 12"));
	EXPECT_FALSE(checkMonth("-12"));
	//Leap Test
	EXPECT_TRUE(isLeapYear(2004));
	EXPECT_TRUE(isLeapYear(2008));
	EXPECT_TRUE(isLeapYear(2400));
	EXPECT_FALSE(isLeapYear(2300));
	EXPECT_FALSE(isLeapYear(2100));
	//Day Test
	EXPECT_TRUE(checkDay("29", "02", "2004"));
	EXPECT_FALSE(checkDay("29", "02", "2003"));
	EXPECT_TRUE(checkDay("30", "4", "2004"));
	EXPECT_FALSE(checkDay("31", "4", "2004"));
	EXPECT_FALSE(checkDay("0", "5", "2002"));
	EXPECT_FALSE(checkDay("-1", "5", "2002"));
	EXPECT_FALSE(checkDay("32", "5", "2002"));
	// Date Test
	EXPECT_EQ(checkDate("2024-05-15"), "2024-05-15");
	EXPECT_EQ(checkDate("2003-02-29"), "Error: Bad input -> 2003-02-29");
	EXPECT_EQ(checkDate("2004-02-29"), "2004-02-29");
	EXPECT_EQ(checkDate("2002-11-31"), "Error: Bad input -> 2002-11-31");
	EXPECT_EQ(checkDate("2001-42-42"), "Error: Bad input -> 2001-42-42");
}

TEST(BitcoinExchange, amount_test) {
	EXPECT_EQ(checkAmount("1"), "1");
	EXPECT_EQ(checkAmount("1000"), "1000");
	EXPECT_EQ(checkAmount("10000"), "Error: too large a number");
	EXPECT_EQ(checkAmount("-1"), "Error: not a positive number");
	EXPECT_EQ(checkAmount("1.0"), "1.0");
	EXPECT_EQ(checkAmount("+1.0"), "+1.0");
	EXPECT_EQ(checkAmount("1.-0"), "Error: not a number");
	EXPECT_EQ(checkAmount("1.+0"), "Error: not a number");
	EXPECT_EQ(checkAmount("-1.0"), "Error: not a positive number");
	EXPECT_EQ(checkAmount("1.0.0"), "Error: not a number");
}

TEST(BitcoinExchange, rate_test) {
	std::map<std::string, float> rate = {{"2024-05-01", 1}, {"2024-05-08", 5}, {"2024-05-15", 10}};
	EXPECT_EQ(getRate("2024-05-15", rate), 10);
	EXPECT_EQ(getRate("2024-05-14", rate), 5);
	EXPECT_EQ(getRate("2023-05-14", rate), 0);
}

TEST(BitcoinExchange, strToT_test) {
	EXPECT_EQ(strToT<int>("+1"), 1);
	EXPECT_EQ(strToT<int>("-1"), -1);
}




