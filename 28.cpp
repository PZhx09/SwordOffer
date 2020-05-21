#include<iostream>
using namespace std;
  //Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
class Solution {
public:
    //�Ҿ������  
    //�����������ڵ���ͬ�������������Ӻ����������Һ���ͬ�����㣬���������Һ��Ӻ�������������ͬ������
    bool isSymmetric(TreeNode* root) {
        if (root == NULL)
            return true;
        return checkLeftandRight(root->left, root->right);

    }
    bool checkLeftandRight(TreeNode* leftNode, TreeNode* rightNode)
    {
        if (leftNode == NULL && rightNode == NULL)
            return true;
        if (leftNode == NULL || rightNode == NULL)
            return false;
        if (leftNode->val != rightNode->val)
            return false;
        bool result = true;
        if (leftNode->left != NULL || rightNode->right != NULL)
            result = result & checkLeftandRight(leftNode->left, rightNode->right);
        if (leftNode->right != NULL || rightNode->left != NULL)
            result = result & checkLeftandRight(leftNode->right, rightNode->left);
        return result;
    }
};