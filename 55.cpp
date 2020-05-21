#include<iostream>
using namespace std;



 // Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
class Solution {
public:
    //��һֱ���뵽�ķ������ݹ�  ������ȵ�������������������+1   ����ʱ������   37/39  ˵����������ȷ��
    /*  
    int maxDepth(TreeNode* root) {
        if (root == NULL)
            return 0;
        return maxDepth(root->left) > maxDepth(root->right) ? maxDepth(root->left) + 1 : maxDepth(root->right) + 1;
    }*/
    //ͬ���Ǳ����ݹ飬������Ϊ����ÿ�����ڵ㣬���������Σ�����ʱ��δ����
    int maxDepth(TreeNode* root) {
        if (root == NULL)
            return 0;
        int left=0, right=0;
        if (root->left != NULL)
            left = maxDepth(root->left);
        if (root->right != NULL)
            right = maxDepth(root->right);
        return left > right ?  left + 1 : right + 1;
    }
};