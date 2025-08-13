#include "PmergeMe.hpp"
#include <gtest/gtest.h>

TEST(pmergeMe, strToInt) {
	EXPECT_EQ(strToInt("0"), 0);
	EXPECT_EQ(strToInt("10"), 0);
	EXPECT_EQ(strToInt("1000"), 0);
	EXPECT_EQ(strToInt("2147483647"), 0);
	EXPECT_EQ(strToInt("2147483648"), 0);
	EXPECT_EQ(strToInt("-2147483648"), -1);
	EXPECT_EQ(strToInt("-28"), -1);
}
