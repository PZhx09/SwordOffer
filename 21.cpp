#include<iostream>
#include<vector>
using namespace std;

//第一次做，超出时间限制  
//算法应该是对的，所以可能是时间复杂度的问题
//这里怀疑是push_back和erase这两个函数的事
/*class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int i = 0;
        int j = nums.size();
        while (i != nums.size()&&i!=j)
        {
            if (nums[i] % 2 == 0)
            {
                int tmp = nums[i];
                nums.erase(nums.begin() + i);
                nums.push_back(tmp);
                j--;
                continue;
            }
            i++;
        }
        return nums;
    }
};*/
class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        if (nums.size() == 0)
            return nums;
        int i = 0;
        int j = nums.size()-1;
        //这里i和j的移动条件还可一遍一遍
        //i指向奇数自动向后，j指向偶数自动向前
        while (i != j)
        {
            if (nums[i] % 2 == 1)
            {
                i++;
                continue;
            }
            int tmp = nums[i];
            nums[i] = nums[j];
            nums[j] = tmp;
            j--;
        }
        return nums;
    }
};
/*int main()
{
    Solution s1;
    vector<int> nums = { 1,2,3,4 };
    s1.exchange(nums);
}*/