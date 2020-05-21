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

 //����ڵ�Ӻ���ǰ���޷�����ջ��ջ
 //���⣬������������޸ĵĻ������Ա�������Ĺ����а�����ָ�뷴����
class Solution {
public:
    vector<int> reversePrint(ListNode* head) {

        vector<int> forward, reverse;//����������û��Ҫ���������������Ƿ���
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