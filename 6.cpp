#include<iostream>
#include<vector>
#include<string>
using namespace std;

// Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

 //链表节点从后向前，无非是入栈出栈
 //另外，输入如果可以修改的话，可以遍历链表的过程中把链表指针反过来
class Solution {
public:
    vector<int> reversePrint(ListNode* head) {

        vector<int> forward, reverse;//如果是输出就没必要两个，但是这里是返回
        ListNode* tmp = head;
        if (head == NULL)
            return reverse;
        forward.push_back(tmp->val);
        while (tmp->next != NULL)
        {
            tmp = tmp->next;
            forward.push_back(tmp->val);
        }
        for (int i = forward.size() - 1; i >= 0; i--)
            reverse.push_back(forward[i]);
        return reverse;
    }
};