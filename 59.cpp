#include<iostream>
#include<vector>
#include<deque>
using namespace std;

class Solution {
public:
    //�����ˣ������α�������
    //ʱ�临�Ӷ�O(k*n)���ռ临�Ӷ�O(1)  ʱ��16% �ռ�100%
    /*
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        //���������е����ֵ   �ⶼû���� ����������
        if (nums.empty())
            return {};
        vector<int> ans;
        for (int i = 0; i < nums.size() - k + 1; i++)
            ans.push_back(max(nums, k, i));
        return ans;
    }
    int max(vector<int>& nums, int k, int start)
    {
        int max = nums[start];
        for (int i = 0; i < k; i++)
        {
            if (max < nums[start + i])
                max = nums[start + i];
        }
        return max;
    }
    */
    //˫�˶��з���ʼ�ձ�֤�����ײ������ֵ
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        //���������е����ֵ   �ⶼû���� ����������
        if (nums.empty())
            return {};
        vector<int> ans;
        deque<int> maxque;//���д���±����   �ܹ��ж�ʲôʱ��ó�����
        for (int i = 0; i < nums.size(); i++)
        {
            //��i�ӽ�ջ
            while (!maxque.empty() && nums[i] > nums[maxque.back()])
                maxque.pop_back();
            maxque.push_back(i);
            if (maxque.front() < i - k + 1)//�ж϶���Ԫ���Ƿ��ǳ��˻������ڵ�����
                maxque.pop_front();
            if (i >= k - 1)
                ans.push_back(nums[maxque.front()]);
        }
        return ans;
    }
};

int main()
{
    vector<int> test = { 7,2,4 };
    Solution s1;
    s1.maxSlidingWindow(test, 2);

}