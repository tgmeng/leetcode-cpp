#pragma once
#include <vector>

using namespace std;

/**
 * https://leetcode.cn/problems/binary-search/
 */
class BinarySearchSolution {
public:
  virtual int search(vector<int> &nums, int target) = 0;
};

class BasicBinarySearchSolution : BinarySearchSolution {
public:
  int search(vector<int> &nums, int target) {
    int left = 0;
    int right = nums.size() - 1;
    // 这里用 ==: 想找的数在两端(最末尾或者开头)
    while(left <= right) {
      int mid = (right - left) / 2 + left;
      if (nums[mid] == target) {
        return mid;
      }
      // +1/-1: nums[mid] != target 则直接跳过, 选
      if (nums[mid] > target) {
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }
    return -1;
  }
};
