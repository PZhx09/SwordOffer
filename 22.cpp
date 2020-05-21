#include<iostream>

using namespace std;
//  Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution {
public:
    //这里其实要考虑程序的鲁棒性，问题不难，所以这里要注意
    //1.head不能为空
    //2.k不能大于链表长度
    //3.k必须为正数
    ListNode* getKthFromEnd(ListNode* head, int k) {
        if (head == NULL)
            return NULL;
        if (k <= 0)
            return NULL;

        ListNode *iteraterK = head;
        ListNode* iterator = head;
        int i = 0;
        while (i < k)
        {
            i++;
            iteraterK = iteraterK ->next;
            if (iteraterK == NULL && i < k)
                return NULL;
        }
        while (iteraterK != NULL)
        {
            iterator = iterator->next;
            iteraterK = iteraterK->next;
        }
        return iterator;

    }
};