#include <gmock/gmock-matchers.h>
#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "189-rotate-array.h"

using namespace std;
using namespace testing;

void runTests(RotateArraySolution &solution) {
  auto data1 = vector<int>{1, 2, 3, 4, 5, 6, 7};
  solution.rotate(data1, 3);
  ASSERT_THAT(data1, ElementsAre(5, 6, 7, 1, 2, 3, 4));

  auto data2 = vector<int>{-1, -100, 3, 99};
  solution.rotate(data2, 2);
  ASSERT_THAT(data2, ElementsAre(3, 99, -1, -100));

  auto data3 = vector<int>{-1};
  solution.rotate(data3, 2);
  ASSERT_THAT(data3, ElementsAre(-1));
}

TEST(RotateArray, Basic) {
  FoolRotateArraySolution solution;
  runTests(solution);

  ReverseRotateArraySolution flipSolution;
  runTests(flipSolution);

  RingReplacementRotateArraySolution ringReplacementSolution;
  runTests(ringReplacementSolution);
}
