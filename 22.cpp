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
    //������ʵҪ���ǳ����³���ԣ����ⲻ�ѣ���������Ҫע��
    //1.head����Ϊ��
    //2.k���ܴ���������
    //3.k����Ϊ����
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