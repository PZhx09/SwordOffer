#include<iostream>
#include<vector>
#include<deque>
using namespace std;

class Solution {
public:
    //不想了，先来次暴力遍历
    //时间复杂度O(k*n)，空间复杂度O(1)  时间16% 空间100%
    /*
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        //滑动窗口中的最大值   题都没看清 你做个锤子
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
    //双端队列法，始终保证队列首部是最大值
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        //滑动窗口中的最大值   题都没看清 你做个锤子
        if (nums.empty())
            return {};
        vector<int> ans;
        deque<int> maxque;//队列存放下标更好   能够判断什么时候该出队列
        for (int i = 0; i < nums.size(); i++)
        {
            //将i加进栈
            while (!maxque.empty() && nums[i] > nums[maxque.back()])
                maxque.pop_back();
            maxque.push_back(i);
            if (maxque.front() < i - k + 1)//判断队首元素是否是出了滑动窗口的限制
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