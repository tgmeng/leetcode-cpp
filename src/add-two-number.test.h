#pragma once
#include <gtest/gtest.h>
#include "./add-two-number.h"

using namespace std;

TEST(AddTwoNumber, Basic) {
	AddTwoNumberSolution sol;
	int depth = sol.addTwoNumbers();
	EXPECT_EQ(depth, 0);
}
