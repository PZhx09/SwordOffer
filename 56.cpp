#include<iostream>
#include<vector>
#include<map>
using namespace std;



class Solution {
public:
    //第一想法:维护两个变量，每次遍历到一个新的元素进行比较，如果不相等继续，相等则表示重读，下个替换回来
    //问题如果是12321  你怎么把3给拿回来？

    //第二想法，借用辅助数据结构map 很简单  但是时间复杂度O(n)  但是空间复杂度也是O(n)   
    //结果正确  时间5.46  空间100  
    /*vector<int> singleNumbers(vector<int>& nums) {
        vector<int> ans;
        map<int, int> data;
        for (int i = 0; i < nums.size(); i++)
            data[nums[i]]++;
        for (int i = 0; i < nums.size(); i++)
        {
            if (data[nums[i]] == 1)
                ans.push_back(nums[i]);
        }
        return ans;
    }*/
    //应该是使用异或  具体看看异或的性质
    //遍历数组，异或一遍 最终得到a^b  但是a和b怎么分离开呢？
    //把a和b分离到两个不同的数组中就行了

    //看了剑指  思路没问题，但是代码过于复杂

    /*
    vector<int> singleNumbers(vector<int>& nums) {
        vector<int> ans;
        int data=0;
        int num1 = 0, num2 = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            data = data ^ nums[i];
        }
        int indexOfOne = getFirstOne(data);

        for (int i = 0; i < nums.size(); i++)
        {
            if (isBitOne(nums[i], indexOfOne))
            {
                num1 = num1 ^ nums[i];
            }
            else
            {
                num2 = num2 ^ nums[i];
            }
        }
        return vector<int>{num1, num2};
    }

    int getFirstOne(int data)
    {
        //返回第一个1所在的位，例如   110  返回1   111返回0  这样
        int indexOfOne = 0;
        while (!(data & 1))
        {
            indexOfOne++;
            data = data >> 1;
        }
        return indexOfOne;
    }
    bool isBitOne(int num, int index)
    {
        num = num >> index;
        return num & 1;
    }
    */
    //看了题解的方法  优化了位操作
    /*vector<int> singleNumbers(vector<int>& nums) {
        int data = 0;
        int num1 = 0, num2 = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            data = data ^ nums[i];
        }
        int indexOfOne =0;
        while (!(data & 1))
        {
            indexOfOne++;
            data=data >> 1;
        }
            

        for (int i = 0; i < nums.size(); i++)
        {
            if ((nums[i]>>indexOfOne)&1)
            {
                num1 = num1 ^ nums[i];
            }
            else
            {
                num2 = num2 ^ nums[i];
            }
        }
        return vector<int>{num1, num2};
    }*/
    //看了评论的操作  怪物级别
    vector<int> singleNumbers(vector<int>& nums) {
        int data = 0;
        int num1 = 0, num2 = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            data = data ^ nums[i];
        }
        int k = data & (-data);
        for (int i = 0; i < nums.size(); i++)
        {
            if (k & nums[i])
                num1 ^= nums[i];
            else
                num2 ^= nums[i];
        }
        return vector<int>{num1, num2};
    }
};


/*int main()
{
    int a = 4;
    int b = 3;
    int c = a ^ b;
    Solution s1;
}*/