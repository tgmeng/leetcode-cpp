#include <gtest/gtest.h>
#include <vector>
#include "./two-sum.h"

double getSum(std::vector<int> input, std::vector<int> list) {
  double sum = 0;
  for (std::vector<int>::iterator it = list.begin(); it != list.end(); ++it) {
    sum += input[*it];
  }
  return sum;
}

TEST(Easy, TwoSum) {
  SolutionForTwoSum sol;
  std::vector<int> input = {3, 2, 3};
  int result = 6;

  EXPECT_EQ(getSum(input, sol.twoSum(input, result)), result);
  EXPECT_EQ(getSum(input, sol.twoSumWithHash(input, result)), result);
}
