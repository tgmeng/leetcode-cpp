#include <gmock/gmock-matchers.h>
#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "167-two-sum-ii.h"

using namespace std;
using namespace testing;

void runTests(TwoSumIISumSolution &solution) {
  auto data1 = vector<int>{2, 7, 11, 15};
  ASSERT_THAT(solution.twoSum(data1, 9), ElementsAre(1, 2));

  auto data2 = vector<int>{-1, 0};
  ASSERT_THAT(solution.twoSum(data2, -1), ElementsAre(1, 2));

  auto data3 = vector<int>{2, 3, 4};
  ASSERT_THAT(solution.twoSum(data3, 6), ElementsAre(1, 3));
}

TEST(TwoSumIISum, Basic) {
  DoublePointerTwoSumIISumSolution solution;
  runTests(solution);
}
