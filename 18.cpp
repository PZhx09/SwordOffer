#include<iostream>
using namespace std;

 // Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        if (head->val == val)
            return head->next;

        ListNode* pre = head;
        ListNode* current = head->next;
        while (current->val != val)
        {
            pre = current;
            current = current->next;
        }
        pre->next = current->next;
        return head;
    }
};