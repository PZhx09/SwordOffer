#include<iostream>
#include<vector>
#include<map>
#include<set>
using namespace std;


class Solution {
public:
    //先用map试试   key装值，value装坐标  时间性能很差
    /*vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        map<int, int> data;
        for (int i = 0; i < nums.size(); i++)
        {
            if (data.find(target - nums[i]) != data.end())
            {
                ans.push_back(target - nums[i]);
                ans.push_back( nums[i]);
                return ans;
            }
            data[nums[i]] = i;
        }
        return ans;
    }*/
    //用set试一试
    //set方法没有问题   时间复杂度和空间复杂度都是O(n)
    /*vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        set<int> data;
        for (int i = 0; i < nums.size(); i++)
        {
            if (data.find(target - nums[i]) != data.end())
            {
                ans.push_back(target - nums[i]);
                ans.push_back(nums[i]);
                return ans;
            }
            data.insert(nums[i]);
        }
        return ans;
    }*/
    //不过set方法没有利用到递增数组这个性质
    //采用双指针法
    vector<int> twoSum(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        int sum = 0;
        /*while (nums[low] + nums[high] != target)
        {
            if (nums[low] + nums[high] > target)
                high--;
            else
                low++;
        }*/ //学学别人的写法
        while (low < high)
        {
            sum = nums[low] + nums[high];
            if (sum == target)
            {
                break;
            }
            if (sum < target)
                low++;
            else
                high--;
        }

        return vector<int>{nums[low],nums[high]};
    }
};

/*int main()
{
    map<int, int> data;
}*/