#pragma once

using namespace std;

bool isBadVersion(int version) {
  return version >= 4;
}

/**
 * https://leetcode.cn/problems/first-bad-version/
 */
class FirstBadVersionSolution {
public:

  int firstBadVersion(int n);
};

class BasicFirstBadVersionSolution : FirstBadVersionSolution {
public:
  int firstBadVersion(int n) {
    int left = 1;
    int right = n;
    while(left <= right) {
      int mid = (right - left) / 2 + left;
      if (isBadVersion(mid)) {
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }
    return left;
  }
};
