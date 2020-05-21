#include<iostream>
#include<vector>
#include<queue>
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
    vector<int> levelOrder(TreeNode* root) {
        vector<int> result;
        if (root == NULL)
            return result;
        queue<TreeNode*> nodeQueue;
        nodeQueue.push(root);
        while (!nodeQueue.empty())
        {
            TreeNode* tmp = nodeQueue.front();
            nodeQueue.pop();
            result.push_back(tmp->val);
            if (tmp->left != NULL)
                nodeQueue.push(tmp->left);
            if (tmp->right != NULL)
                nodeQueue.push(tmp->right);
        }
        return result;
    }
};