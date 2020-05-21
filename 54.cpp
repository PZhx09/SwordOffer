#include<iostream>
#include<vector>

using namespace std;

//  Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
class Solution {
public:
    int kthLargest(TreeNode* root, int k) {
        if (root == NULL)
            return -1;
        int ans=0;
        int order = 0;
        reverseLDR(root,order, k, ans);
        return ans;
    }
    bool reverseLDR(TreeNode* root,int &order, int k, int &ans)
    {
        if (root == NULL)
            return false;
        if (reverseLDR(root->right, order, k, ans))
            return true;
        order++;
        if (order == k)
        {
            ans = root->val;
            return true;
        }

        if (reverseLDR(root->left, order, k, ans))
            return true;

        return false;

    }
};