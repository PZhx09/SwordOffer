#include<iostream>
#include<vector>
using namespace std;
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};

class Solution {
public:
    //双向链表排序，其实就是中序遍历的顺序
    //那么只要中序遍历一次，然后修改指针方向，就可以了

    //我这里使用了辅助空间
    //剑指offer上的方法:采用递归的方法，一样是中序遍历，先处理左子树，处理后的节点与根节点连接，再处理右子树，这里的处理就是递归
    Node* treeToDoublyList(Node* root) {
        if (root == NULL)
            return NULL;
        vector<Node*> nodeList;
        LDR(root, nodeList);
        for(int i=0;i< nodeList.size()-1;i++)
        {
            nodeList[i]->right= nodeList[i + 1];
            nodeList[i + 1]->left = nodeList[i];
        }
        nodeList.front()->left = nodeList.back();
        nodeList.back()->right = nodeList.front();
        return nodeList.front();
    }

    void LDR(Node* root,vector<Node*>& nodeList)
    {
        if (root->left != NULL)
            LDR(root->left, nodeList);
        nodeList.push_back(root);
        if (root->right != NULL)
            LDR(root->right, nodeList);
    }
};