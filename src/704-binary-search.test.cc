#include <gtest/gtest.h>
#include <vector>
#include "./704-binary-search.h"

using namespace std;

TEST(BinarySearch, Basic) {
  BasicBinarySearchSolution sol;
  auto list = vector<int>{-1,0,3,5,9,12};
  EXPECT_EQ(sol.search(list, 9), 4);
  EXPECT_EQ(sol.search(list, -1), 0);
  EXPECT_EQ(sol.search(list, 10), -1);
  EXPECT_EQ(sol.search(list, 12), 5);

  list = vector<int>{5};
  EXPECT_EQ(sol.search(list, 5), 0);

}
