#include "RPN.hpp"
#include <gtest/gtest.h>

TEST(rpn_test, checkElType) {
	rpn a;
	EXPECT_EQ(a.checkElType("0"), NUM);
	EXPECT_EQ(a.checkElType("1"), NUM);
	EXPECT_EQ(a.checkElType("2"), NUM);
	EXPECT_EQ(a.checkElType("3"), NUM);
	EXPECT_EQ(a.checkElType("4"), NUM);
	EXPECT_EQ(a.checkElType("5"), NUM);
	EXPECT_EQ(a.checkElType("6"), NUM);
	EXPECT_EQ(a.checkElType("7"), NUM);
	EXPECT_EQ(a.checkElType("8"), NUM);
	EXPECT_EQ(a.checkElType("9"), NUM);
	EXPECT_EQ(a.checkElType("+"), OPR);
	EXPECT_EQ(a.checkElType("-"), OPR);
	EXPECT_EQ(a.checkElType("*"), OPR);
	EXPECT_EQ(a.checkElType("/"), OPR);
	EXPECT_EQ(a.checkElType("10"), ERR);
}


TEST(rpn_test, count_element) {
	rpn a;
	EXPECT_EQ(a.count_element("7 7 * 7 /"), 5);
}
