#pragma once
#include <vector>

using namespace std;

/**
 * https://leetcode.cn/problems/two-sum-ii-input-array-is-sorted/
 */
class TwoSumIISumSolution {
public:
  virtual vector<int> twoSum(vector<int> &numbers, int target) = 0;
};

/**
 * 双指针
 */
class DoublePointerTwoSumIISumSolution : public TwoSumIISumSolution {
public:
  vector<int> twoSum(vector<int> &numbers, int target) override {
    int left = 0;
    int right = numbers.size() - 1;
    while (left < right) {
      int sum = numbers[left] + numbers[right];
      if (target == sum) {
        return vector<int>{left + 1, right + 1};
      }
      if (target > sum) {
        left++;
      } else {
        right--;
      }
    }
    return vector<int>{0, 0};
  }
};