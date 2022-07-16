#pragma once
#include <vector>

using namespace std;

/**
 * https://leetcode.cn/problems/search-insert-position/
 */
class SearchInsertPositionSolution {
public:
  int searchInsert(vector<int>& nums, int target);
};

class BasicSearchInsertPositionSolution : SearchInsertPositionSolution {
public:
  int searchInsert(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;
    while (left <= right) {
      int mid = (right - left) / 2 + left;
      if (nums[mid] == target)  {
        return mid;
      }
      if (nums[mid] > target) {
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }
    return left;
  }
};
