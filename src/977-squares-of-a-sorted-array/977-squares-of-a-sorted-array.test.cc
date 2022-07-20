#include "./977-squares-of-a-sorted-array.h"
#include <gmock/gmock.h>
#include <gtest/gtest.h>

using namespace std;

void runTests(SquaresOfASortedArraySolution &solution) {
  auto data1 = vector<int>{-4, -1, 0, 3, 10};
  ASSERT_THAT(solution.sortedSquares(data1), ::testing::ElementsAre(0, 1, 9, 16, 100));
}

TEST(SquaresOfASortedArray, Basic) {
  BasicSquaresOfASortedArraySolution solution;
  runTests(solution);

  QuickSquaresOfASortedArraySolution quickSolution;
  runTests(quickSolution);
}
