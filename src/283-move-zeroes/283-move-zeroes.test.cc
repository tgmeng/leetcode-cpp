#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "./283-move-zeroes.h"

using namespace std;
using namespace testing;

void runTests(MoveZeroesSolution &solution) {
  auto data = vector<int>{0, 1, 0, 3, 12};
  solution.moveZeroes(data);
  ASSERT_THAT(data, ElementsAre(1, 3, 12, 0, 0));
}

TEST(MoveZeroes, Basic) {
  SwapMoveZeroesSolution basicSolution;
  runTests(basicSolution);

  ZeroPaddingMoveZeroesSolution zeroPaddingSolution;
  runTests(zeroPaddingSolution);
}
