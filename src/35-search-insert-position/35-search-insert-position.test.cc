#include <gtest/gtest.h>
#include <vector>

#include "35-search-insert-position.h"

using namespace std;

TEST(SearchInsertPosition, Basic) {
  BasicSearchInsertPositionSolution solution;

  auto data = vector<int>{1,3,5,6};

  EXPECT_EQ(solution.searchInsert(data, 5), 2);
  EXPECT_EQ(solution.searchInsert(data, 2), 1);
  EXPECT_EQ(solution.searchInsert(data, 7), 4);
}
