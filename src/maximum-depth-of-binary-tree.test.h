#pragma once
#include "maximum-depth-of-binary-tree.h"
#include <gtest/gtest.h>

TEST(MaximumDepthOfBinaryTree, Test) {
	Solution sol;
	int depth = sol.maxDepth(NULL);
	EXPECT_EQ(depth, 0);
}