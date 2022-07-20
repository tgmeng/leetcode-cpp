#pragma once
#include <cmath>
#include <vector>

using namespace std;

/**
 * https://leetcode.cn/problems/squares-of-a-sorted-array/
 */
class SquaresOfASortedArraySolution {
public:
  virtual vector<int> sortedSquares(vector<int> &nums) = 0;
};

class QuickSquaresOfASortedArraySolution
    : public SquaresOfASortedArraySolution {
public:
  vector<int> sortedSquares(vector<int> &nums) override {
    int size = nums.size();
    vector<int> result(nums.size());
    int left = 0;
    int right = size - 1;
    int resultIndex = size - 1;
    while (left <= right) {
      int leftValue = nums[left] * nums[left];
      int rightValue = nums[right] * nums[right];
      if (leftValue > rightValue) {
        result[resultIndex] = leftValue;
        left++;
      } else {
        result[resultIndex] = rightValue;
        right--;
      }
      resultIndex--;
    }
    return result;
  }
};

class BasicSquaresOfASortedArraySolution
    : public SquaresOfASortedArraySolution {
public:
  vector<int> sortedSquares(vector<int> &nums) override {
    vector<int> result;
    std::transform(nums.begin(), nums.end(), std::back_inserter(result),
                   [](int value) -> int { return value * value; });
    sort(result.begin(), result.end());
    return result;
  }
};
