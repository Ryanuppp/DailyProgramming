#include<iostream>


using namespace std;

/**
 * Definition for singly-linked list.*/
struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
  ListNode* deleteDuplicates(ListNode* head) {
    ListNode myhead(-101, head);
    ListNode* cur = myhead.next;
    ListNode* pre = &myhead;
    int last_num = -101;
    while (cur != nullptr && cur->next != nullptr) {
      if (cur->val == cur->next->val) {
        last_num = cur->val;
        while (cur != nullptr && cur->val == last_num) {
          cur = cur->next;
        }
        pre->next = cur;
      }
      else {
        pre = cur;
        cur = cur->next;
      }
    }
    return myhead.next;
  }
};

