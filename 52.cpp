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
    //找出第一个公共节点
    //第一直觉的方法，遍历第一个链表，加到set中，遍历第二个，遇到第一个重复的返回。时间复杂度O(n)，空间复杂度O(n)
    //过了，但是时间复杂度很差
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
    //但是题目说最好使用O(1)的内存
    //使用双指针，很巧妙的一个方法
    //比较长度，长的先走
    //很出乎意料，这个反而快？
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