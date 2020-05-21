#include<iostream>
#include<set>
using namespace std;

  //Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution {
public:
    //�ҳ���һ�������ڵ�
    //��һֱ���ķ�����������һ�������ӵ�set�У������ڶ�����������һ���ظ��ķ��ء�ʱ�临�Ӷ�O(n)���ռ临�Ӷ�O(n)
    //���ˣ�����ʱ�临�ӶȺܲ�
    /*ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        set<ListNode*> seta;
        while (headA != NULL)
        {
            seta.insert(headA);
            headA = headA->next;
        }
        while (headB != NULL)
        {
            if (seta.find(headB)!=seta.end())
                return headB;
            headB = headB->next;
        }
        return NULL;
    }*/
    //������Ŀ˵���ʹ��O(1)���ڴ�
    //ʹ��˫ָ�룬�������һ������
    //�Ƚϳ��ȣ���������
    //�ܳ������ϣ���������죿
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        int lengthA = 0, lengthB = 0;
        ListNode* tmp = headA;
        while (tmp != NULL)
        {
            lengthA++;
            tmp = tmp->next;
        }
        tmp = headB;
        while (tmp != NULL)
        {
            lengthB++;
            tmp = tmp->next;
        }
        ListNode* lList = lengthA < lengthB ? headB : headA;
        ListNode* sList = lengthA < lengthB ? headA : headB;

        for (int i = 0; i < abs(lengthA - lengthB); i++)
            lList = lList->next;
        while (lList != NULL && sList != NULL)
        {
            if (lList == sList)
                return lList;
            lList = lList->next;
            sList = sList->next;
        }
        return NULL;
    }
};