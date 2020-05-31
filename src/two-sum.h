#pragma once
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <ostream>
#include <vector>

using namespace std;

class SolutionForTwoSum {
public:
  /**
   * Brute Force
   * 蛮力解决!
   */
  vector<int> twoSum(vector<int> &nums, int target) {
    for (size_t i = 0; i < nums.size(); i++) {
      for (size_t j = i + 1; j < nums.size(); j++) {
        if (nums[i] + nums[j] == target) {
          return vector<int>{static_cast<int>(i), static_cast<int>(j)};
        }
      }
    }

    return vector<int>{};
  }

  /**
   * 遍历之后, 数值作 key, index 作值, 保存 Hash 中
   * 之后可以根据这个 Hash 回溯了～
   */
  vector<int> twoSumWithHash(vector<int> &nums, int target) {
    unordered_map<int, int> hash;
    for (size_t i = 0; i < nums.size(); i++) {
      int num = nums[i];
      int rest = target - num;

      if (hash.find(rest) != hash.end()) {
        return vector<int>{static_cast<int>(hash[rest]), static_cast<int>(i)};
      }

      hash[num] = i;
    }
    return vector<int>{};
  }
};