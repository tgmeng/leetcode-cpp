#pragma once
#include <vector>

using namespace std;

class ReverseStringSolution {
public:
  virtual void reverseString(vector<char> &s) = 0;
};

class BasicReverseStringSolution : public ReverseStringSolution {
public:
  void reverseString(vector<char> &s) {
    int start = 0;
    int end = s.size() - 1;
    while (start < end) {
      swap(s[start], s[end]);
      start++;
      end--;
    }
  }
};
