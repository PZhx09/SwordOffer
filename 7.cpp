#include<iostream>
#include<vector>
using namespace std;


 // Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
  //���̣��ݹ�  ǰ���Ҹ��ڵ�-->��������������-->ǰ���Ҹ��ڵ�
  //˼·û���⣬������Ҫһ���Ĵ��빦�ײ���д����
class Solution {
public:
    TreeNode* traverseTree(vector<int>& preorder, vector<int>& inorder,int Preleftborder,int Prerightborder, int Inleftborder, int Inrightborder)
    {

        if (Preleftborder > Prerightborder|| Inleftborder> Inrightborder)
            return NULL;
        TreeNode* thisnode = new TreeNode(preorder[Preleftborder]);
        if (Preleftborder == Prerightborder)
        {
            return thisnode;
        }

        int rootlocation;
        for (rootlocation = Inleftborder; rootlocation <= Inrightborder; rootlocation++)
        {
            if (preorder[Preleftborder] == inorder[rootlocation])
                break;
        }
        if(rootlocation- Inleftborder>0)
            thisnode->left = traverseTree(preorder, inorder, Preleftborder + 1, Preleftborder + rootlocation - Inleftborder, Inleftborder, rootlocation - 1);
        if (Inrightborder-rootlocation > 0)
            thisnode->right = traverseTree(preorder, inorder, Preleftborder + rootlocation - Inleftborder + 1, Prerightborder, rootlocation + 1, Inrightborder);
        
        return thisnode;

    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0)
            return NULL;
        return traverseTree(preorder, inorder, 0, preorder.size()-1,0, preorder.size()-1);
    }
};

/*int main()
{
    vector<int> preorder = { 1,2 };
    vector<int> inorder = {2,1};
    Solution s1;
    s1.buildTree(preorder, inorder);
}*/