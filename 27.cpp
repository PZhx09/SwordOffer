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
    //ֱ��˼·�����нڵ㣬���Ӻ��Һ��ӽ���
    //ֱ��AC
    TreeNode* mirrorTree(TreeNode* root) {
        if (root == NULL)
            return NULL;
        TreeNode* tmp = root->left;
        root->left = root->right;
        root->right = tmp;
        mirrorTree(root->left);
        mirrorTree(root->right);
        return root;
    }
};