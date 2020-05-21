#include<iostream>
#include<vector>
#include<queue>
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
    //每一层输入到一行中
    //思路:下一行由上一行生成
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root == NULL)
            return result;
        vector<TreeNode*> row1;
        vector<TreeNode*> row2;
        row1.push_back(root);
        while (!row1.empty())
        {
            vector<int> rowval;
            for (int i = 0; i < row1.size(); i++)
            {
                rowval.push_back(row1[i]->val);
                if (row1[i]->left != NULL)
                    row2.push_back(row1[i]->left);
                if (row1[i]->right != NULL)
                    row2.push_back(row1[i]->right);
            }
            result.push_back(rowval);
            row1 = row2;
            row2 = vector<TreeNode*>();
        }
        return result;
    }
};