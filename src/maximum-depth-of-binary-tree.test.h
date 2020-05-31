#pragma once
#include <gtest/gtest.h>
#include "./maximum-depth-of-binary-tree.h"

TEST(BinaryTree, MaximumDepthOfBinaryTree) {
	Solution sol;
	int depth = sol.maxDepth(NULL);
	EXPECT_EQ(depth, 0);
}
