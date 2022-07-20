#pragma once
#include <vector>

using namespace std;

class RotateArraySolution {
public:
  virtual void rotate(vector<int> &nums, int k) = 0;
};

/**
 * 傻子方法
 * 操作另外一个数组, 然后拷贝值
 */
class FoolRotateArraySolution : public RotateArraySolution {
public:
  void rotate(vector<int> &nums, int k) override {
    int size = (int)nums.size();
    auto buffer = vector<int>(size);
    for (int index = 0; index < size; ++index) {
      int bufferIndex = (index + k) % size;
      buffer[bufferIndex] = nums[index];
    }
    nums.assign(buffer.begin(), buffer.end());
  }
};

/**
 * 如题反转数组
 */
class ReverseRotateArraySolution : public RotateArraySolution {
private:
  static void reverse(vector<int> &nums, int start, int end) {
    while (start < end) {
      int buffer = nums[end];
      nums[end] = nums[start];
      nums[start] = buffer;
      start++;
      end--;
    }
  }

public:
  void rotate(vector<int> &nums, int k) override {
    k = k % nums.size();
    reverse(nums, 0, nums.size() - 1);
    reverse(nums, 0, k - 1);
    reverse(nums, k, nums.size() - 1);
    // 也可用 std::reverse
    // std::reverse(nums.begin(), nums.end());
    // std::reverse(nums.begin(), nums.begin() + k);
    // std::reverse(nums.begin() + k, nums.end());
  }
};

/**
 *
 */
class RingReplacementRotateArraySolution : public RotateArraySolution {
public:
  void rotate(vector<int> &nums, int k) override {}
};
