#include<iostream>
using namespace std;

 // Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
//����˼·û�����⣬������Щϸ�ڿ��ԸĽ���
  //��ΪҪ������ͷ�ڵ㣬����������ʹ�õ����ȶ������һ�αȽ�
  //���ǿ�������һ����Ч��ͷ�ڵ�������
  //³�������⣬���l1��l2��һ���ǿ���ô��
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