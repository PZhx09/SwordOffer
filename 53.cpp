#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    /*int search(vector<int>& nums, int target) {
        //遍历数组，发现target，count++
        int count = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == target)
                count++;
        }
        return count;
    }*/
    //有没有更快的方法？上面的时间复杂度是O(n)
    //已经知道是排序数组了  仔细读题   和上面的没有什么区别  都是顺序查找  时间复杂度也是O(n)
    /*int search(vector<int>& nums, int target) {
        //遍历数组，发现target，count++
        if (nums.empty())
            return 0;
        int count = 0;
        int iterator = 0;
        while (iterator<nums.size()&&nums[iterator] < target)
            iterator++;
        while (iterator < nums.size()&&nums[iterator] == target)
        {
            count++;
            iterator++;
        }
        return count;
    }*/
    //能不能二分查找？
    //利用二分查找，找左边界和右边界
    //别被别人的思路限制
    //这里就存在一个逼近的问题，(l+r)/2，由于向下取整的缘故，天然就
    int search(vector<int>& nums, int target) {
        //两次二分查找来定位左边界和右
        if (nums.empty())
            return 0;
        int low = 0, high = nums.size() - 1;
        int mid=0;
        while (low < high)
        {
            mid = (low + high) / 2;
            if (nums[mid] < target)
            {
                low = mid + 1;
            }
            else if (nums[mid] > target)
            {
                high = mid - 1;
            }
            else
            {
                //mid的数字等于target
                high = mid;  //向左逼近
            }
        }
        if (nums[low] != target)
            return 0;
        int x = low;
        high = nums.size() - 1;
        while (low < high)
        {
            mid = (low + high+1) / 2;
            if (nums[mid] < target)
            {
                low = mid + 1;
            }
            else if (nums[mid] > target)
            {
                high = mid - 1;
            }
            else
            {
                //mid的数字等于target
                low = mid;  //向右逼近  这里逼近存在一个问题   例如  4  5 中找4
            }
        }
        return high - x + 1;
    }

};

/*int main()
{
    vector<int> test = { 5,7,7,8,8,10 };
    Solution s1;
    cout<<s1.search(test, 8);
}*/