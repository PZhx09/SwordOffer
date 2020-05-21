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
      //思路:先找到与B的根节点相同的节点    遍历树，递归最方便
      //从B的根节点，向左向右，递归到空为止
      bool isSubStructure(TreeNode* A, TreeNode* B) {
          if (A == NULL || B == NULL)
              return false;
          //遍历A树，找到B根节点相同的节点
          vector<TreeNode*> rootsInA;
          traverseTree(A, B, rootsInA);
          while (!rootsInA.empty())
          {
              TreeNode* rootInA = rootsInA.back();
              rootsInA.pop_back();
              if (compareTwoTree(rootInA, B))
                  return true;
          }
          return false;

      }
      void traverseTree(TreeNode* A,TreeNode* Broot,vector<TreeNode*>& rootsInA)
      {
          if (A != NULL)
          {
              if (A->val == Broot->val)
                  rootsInA.push_back(A);
              traverseTree(A->left, Broot, rootsInA);
              traverseTree(A->right, Broot, rootsInA);
          }
      }
      bool compareTwoTree(TreeNode* rootInA, TreeNode* B)
      {
          bool result = true;
          if (B->left != NULL)
          {
              if (rootInA->left == NULL|| rootInA->left->val!= B->left->val)
                  return false;
              result = result & compareTwoTree(rootInA->left, B->left);
          }
          if (B->right != NULL)
          {
              if (rootInA->right == NULL|| rootInA->right->val != B->right->val)
                  return false;
              result = result & compareTwoTree(rootInA->right, B->right);
          }
          return result;
      }
};
  /*int main()
  {
      Solution s1;
      TreeNode* T3 = new TreeNode(3);
      TreeNode* T4 = new TreeNode(4);
      TreeNode* T5 = new TreeNode(5);
      TreeNode* T1 = new TreeNode(1);
      TreeNode* T2 = new TreeNode(2);
      T3->left = T4;
      T3->right = T5;
      T4->left = T1;
      T4->right = T2;

      TreeNode* B4 = new TreeNode(4);
      TreeNode* B1 = new TreeNode(1);
      B4->left = B1;
      cout << s1.isSubStructure(T3, B4);

  }*/