#include "PmergeMe.hpp"
#include <gtest/gtest.h>

TEST(pmergeMe, strToInt) {
	EXPECT_EQ(strToInt("0"), 0);
	EXPECT_EQ(strToInt("10"), 10);
	EXPECT_EQ(strToInt("1000"), 1000);
	EXPECT_EQ(strToInt("2147483647"), 2147483647);
	EXPECT_THROW(strToInt("2147483648"), std::runtime_error);
	EXPECT_EQ(strToInt("-2147483648"), -2147483648);
	EXPECT_EQ(strToInt("-28"), -28);
}

TEST(pmergeMe, isValidNumber) {
	EXPECT_TRUE(isValidNumber("0"));
	EXPECT_TRUE(isValidNumber("100"));
	EXPECT_TRUE(isValidNumber("2147483647"));
	EXPECT_FALSE(isValidNumber("10 10"));
	EXPECT_FALSE(isValidNumber("-10"));
	EXPECT_FALSE(isValidNumber("10.0f"));
	EXPECT_FALSE(isValidNumber("aaa"));
	EXPECT_FALSE(isValidNumber("+10"));
}

TEST(pmergeMe, init_argument) {
    const char* argv[] = {"./a.out", "10", "1", "100", "2147483647", "91876"};
    const char* argv1[] = {"./a.out", "-10", "1", "100", "2147483647", "91876"};
	std::list<int> first = init_argument(6, argv);
	std::list<int> expected{10, 1, 100, 2147483647, 91876};
	EXPECT_EQ(first, expected);   
	EXPECT_THROW(init_argument(6, argv1), std::runtime_error);
}




