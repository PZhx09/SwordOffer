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
    //˫������������ʵ�������������˳��
    //��ôֻҪ�������һ�Σ�Ȼ���޸�ָ�뷽�򣬾Ϳ�����

    //������ʹ���˸����ռ�
    //��ָoffer�ϵķ���:���õݹ�ķ�����һ��������������ȴ����������������Ľڵ�����ڵ����ӣ��ٴ���������������Ĵ�����ǵݹ�
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