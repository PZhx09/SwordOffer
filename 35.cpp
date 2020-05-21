#include<iostream>
#include<vector>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {

        //1��������ʵ���Բ���vector�洢
        //1����next��ʱ�򣬶�һ��������¼��һ�ڵ������
        //1����random��ʱ�򣬿��Լ�¼random�Ǵ�ͷ���˶��ٲ�   �����Ͳ���Ҫ����ռ�  ʱ�临�Ӷ�O(N2)
        //2�����ʹ�ö���ռ�(���������˶���ռ䣬��û����ٶ�)�����Կ�����map<ԭ�ڵ㣬�½ڵ�>��������random��ʱ���ӶȾ���O(n),���帴�ӶȾ���O(n)
        //3����ѷ���:��ʹ�ø����ռ�ʱ�临�Ӷ�ΪO(n)-->���ƽڵ��ʱ���½ڵ�ӵ��ɽڵ����(val��next������),����random��ʱ��origin->random->next���½ڵ��random��ʱ�临�Ӷ���O(n)
        if (head == NULL)
            return NULL;
        vector<Node*> originList;
        vector<Node*> copyList;
        Node* traverseOrigin= head;
        Node* copyNode;
        //�ȸ���val
        while (traverseOrigin != NULL)
        {
            copyNode = new Node(traverseOrigin->val);
            copyList.push_back(copyNode);
            originList.push_back(traverseOrigin);
            traverseOrigin = traverseOrigin->next;
        }
        //����next
        for (int i = 0; i < copyList.size() - 1; i++)
        {
            copyList[i]->next = copyList[i + 1];
        }
            
        copyList.back()->next = NULL;
        //����random
        for (int i = 0; i < copyList.size(); i++)
        {
            if (originList[i]->random == NULL)
            {
                copyList[i]->random = NULL;
            }
            else
            {
                int location = 0;
                while (originList[i]->random != originList[location])
                    location++;
                copyList[i]->random = copyList[location];
            }
        }

        return copyList[0];
    }
};