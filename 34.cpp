#include<iostream>
#include<vector>
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
    //树中结点可以重复，而且没说正整数
    //递归思路，递归树，根root，所以左右子树路径和为x-root->val
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> result;
        vector<int> path;
        if (root == NULL)
            return result;
        traverseTree(root, sum, result, path);
        return result;

    }
    void traverseTree(TreeNode* root, int sum, vector<vector<int>>& result, vector<int> &path)
    {
        path.push_back(root->val);

        if (root->left == NULL && root->right == NULL)
        {
            if (root->val == sum)
                result.push_back(path);
        }
        else
        {
            if(root->left!=NULL)
                traverseTree(root->left, sum-root->val, result, path);
            if (root->right != NULL)
                traverseTree(root->right, sum - root->val, result, path);
        }


        path.pop_back();
    }

};
/*int main()
{
    vector<vector<int>> result;
    vector<int> test1;
    test1.push_back(1);
    result.push_back(test1);
    test1.push_back(2);

    cout << result[0].size() << endl;
}*/