#pragma once
#include <algorithm>
#include <iostream>
#include <ostream>
#include <unordered_map>
#include <vector>

using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class AddTwoNumberSolution {
public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    int carry = 0;
    ListNode *result = new ListNode();
    ListNode *processResult = result;
    while (l1 != nullptr || l2 != nullptr) {
      int value = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;

      carry = value / 10;

      ListNode *next = new ListNode(value % 10);
      processResult->next = next;
      processResult = next;

      if (l1) {
        l1 = l1->next;
      }
      if (l2) {
        l2 = l2->next;
      }
    }

    if (carry > 0) {
      processResult->next = new ListNode(carry);
    }

    return result->next;
  }
};