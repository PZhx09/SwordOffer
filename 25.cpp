#include<iostream>
using namespace std;

 // Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
//大体思路没有问题，但是有些细节可以改进。
  //因为要先设置头节点，所以我这里使用的是先额外进行一次比较
  //但是可以设置一个无效的头节点来代替
  //鲁棒性问题，如果l1和l2有一个是空怎么办
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *head,*cur;
        head = new ListNode(-1);
        cur = head;
        while(l1&&l2)
        {
            if (l1->val < l2->val)
            {
                cur->next = l1;
                l1 = l1->next;
            }
            else
            {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        cur->next = l1 == NULL ? l2 : l1;
        return head->next;
    }
};