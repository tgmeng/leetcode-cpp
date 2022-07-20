#include "./278-first-bad-version.h"
#include <gtest/gtest.h>

using namespace std;

TEST(FirstBadVersion, Basic) {
  BasicFirstBadVersionSolution solution;
  EXPECT_EQ(solution.firstBadVersion(5), 4);
}
