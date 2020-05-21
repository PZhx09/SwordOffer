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
    bool isBalanced(TreeNode* root) {
        int depth;
        return isBalanced(root, depth);
    }
    bool isBalanced(TreeNode* root, int& depth)
    {
        if (root == NULL)
        {
            depth = 0;
            return true;
        }
        int leftdepth,rightdepth;
        if (!(isBalanced(root->left, leftdepth) && isBalanced(root->right, rightdepth)))
            return false;
        if (abs(leftdepth - rightdepth) > 1)
            return false;
        depth = leftdepth > rightdepth ? leftdepth + 1 : rightdepth + 1;
        return true;

    }
};