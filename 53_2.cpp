#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    //先来一个最简单的方法，顺序遍历
    /*int missingNumber(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++)
            if (i != nums[i])
                return i;
        return nums.size();
    }*/
    //用二分查找试试
    int missingNumber(vector<int>& nums) {
        int low = 0, high = nums.size();//这里high的取值很巧妙，如果high是size-1  最后还要判断一下是不是前面都没有缺数字
        int mid = 0;
        while (low<high)
        {
            mid = (low + high) / 2;
            if (nums[mid] == mid)
            {
                low = mid+1;
            }
            else
            {
                high = mid;
            }
        }

        return low;
    }
};

/*int main()
{
    vector<int> test = {0,1,3};
    Solution s1;
    cout << s1.missingNumber(test);
}*/