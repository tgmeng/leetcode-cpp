#include "344-reverse-string.h"
#include <gmock/gmock.h>
#include <gtest/gtest.h>

using namespace std;
using namespace testing;

void runTests(ReverseStringSolution &solution) {
  vector<char> s = {'h', 'e', 'l', 'l', 'o'};
  solution.reverseString(s);
  ASSERT_THAT(s, ElementsAre('o', 'l', 'l', 'e', 'h'));
}

TEST(ReverseString, Basic) {
  BasicReverseStringSolution solution;
  runTests(solution);
}
