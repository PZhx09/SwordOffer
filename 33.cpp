#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    //二叉搜索树，左边节点一定小于根节点，右边节点一定大于根节点！！！
    //后序遍历，左右中，找到根节点，分出左右，左右子树也都是二叉搜索树
    bool verifyPostorder(vector<int>& postorder) {
        return isBinarySearchTree(postorder, 0, postorder.size() - 1);
    }
    bool isBinarySearchTree(vector<int>& postorder, int start, int end)
    {
        if (start >= end)
            return true;

        //找到根节点
        int root = postorder[end];
        //找到左子树和右子树的分界点，要求左子树节点都小于根节点，右子树节点都大于根节点
        int mid = start;
        while (postorder[mid] < root && mid < end)
            mid++;
        for (int i = mid; i < end; i++)
        {
            if (postorder[i] < root)
                return false;
        }
        return isBinarySearchTree(postorder, start, mid - 1) && isBinarySearchTree(postorder, mid, end - 1);
    }
};