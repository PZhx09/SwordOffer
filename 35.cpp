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

        //1、这里其实可以不用vector存储
        //1、加next的时候，多一个变量记录上一节点就行了
        //1、加random的时候，可以记录random是从头走了多少步   这样就不需要额外空间  时间复杂度O(N2)
        //2、如果使用额外空间(我这里用了额外空间，还没提高速度)，可以考虑用map<原节点，新节点>，这样加random的时候复杂度就是O(n),整体复杂度就是O(n)
        //3、最佳方法:不使用辅助空间时间复杂度为O(n)-->复制节点的时候，新节点加到旧节点后面(val和next都好了),复制random的时候，origin->random->next是新节点的random，时间复杂度是O(n)
        if (head == NULL)
            return NULL;
        vector<Node*> originList;
        vector<Node*> copyList;
        Node* traverseOrigin= head;
        Node* copyNode;
        //先复制val
        while (traverseOrigin != NULL)
        {
            copyNode = new Node(traverseOrigin->val);
            copyList.push_back(copyNode);
            originList.push_back(traverseOrigin);
            traverseOrigin = traverseOrigin->next;
        }
        //复制next
        for (int i = 0; i < copyList.size() - 1; i++)
        {
            copyList[i]->next = copyList[i + 1];
        }
            
        copyList.back()->next = NULL;
        //复制random
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