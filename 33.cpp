#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    //��������������߽ڵ�һ��С�ڸ��ڵ㣬�ұ߽ڵ�һ�����ڸ��ڵ㣡����
    //��������������У��ҵ����ڵ㣬�ֳ����ң���������Ҳ���Ƕ���������
    bool verifyPostorder(vector<int>& postorder) {
        return isBinarySearchTree(postorder, 0, postorder.size() - 1);
    }
    bool isBinarySearchTree(vector<int>& postorder, int start, int end)
    {
        if (start >= end)
            return true;

        //�ҵ����ڵ�
        int root = postorder[end];
        //�ҵ����������������ķֽ�㣬Ҫ���������ڵ㶼С�ڸ��ڵ㣬�������ڵ㶼���ڸ��ڵ�
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