#pragma once
#include <vector>

using namespace std;

/**
 * https://leetcode.cn/problems/move-zeroes/
 */
class MoveZeroesSolution {
public:
  virtual void moveZeroes(vector<int> &nums) = 0;
};

class SwapMoveZeroesSolution : public MoveZeroesSolution {
public:
  void moveZeroes(vector<int> &nums) {
    int left = 0;
    int right = 0;
    while (right < nums.size()) {
      if (nums[right] != 0) {
        swap(nums[left], nums[right]);
        left++;
      }
      right++;
    }
  }
};

class ZeroPaddingMoveZeroesSolution : public MoveZeroesSolution {
public:
  void moveZeroes(vector<int> &nums) {
    int left = 0;
    int right = 0;
    while (right < nums.size()) {
      if (nums[right] != 0) {
        nums[left] = nums[right];
        left++;
      }
      right++;
    }
    for (int i = left; i < nums.size(); ++i) {
      nums[i] = 0;
    }
  }
};
