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
    //第一直觉想到的方法，递归  树的深度等于左右子树的最大深度+1   超出时间限制   37/39  说明方法是正确的
    /*  
    int maxDepth(TreeNode* root) {
        if (root == NULL)
            return 0;
        return maxDepth(root->left) > maxDepth(root->right) ? maxDepth(root->left) + 1 : maxDepth(root->right) + 1;
    }*/
    //同样是暴力递归，但是因为下面每个根节点，少算了两次，所以时间未超出
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