#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    /*bool isStraight(vector<int>& nums) {
        //判断是否为顺子   顺子肯定就是5个来在一起的数字
        //想好再写，第一遍写的稀烂
        //第1遍历数组，找到最小的数字.第2遍遍历，看看是不是都在自己5的范围内   要么超出，要么是king！
        //不要忘了判断是否重复的问题   这个是不排序方式
        int min = 14;//这里可以再维护一个max  这样的话只要判断max-min就可以了
        bool card[14] = { false };
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != 0)
            {
                if(min > nums[i] )
                    min = nums[i];
                if (card[nums[i]])
                    return false;
                card[nums[i]] = true;
            }
                
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] - min > 4)
                return false;
        }
        return true;
    }*/
    //不排序方式  最佳解法?  反而是自己只维护一个min   更快一些
    /*bool isStraight(vector<int>& nums) {

        bool card[14] = { false };
        int min = 15, max = -1;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != 0)
            {
                if (min > nums[i])
                    min = nums[i];
                if (max < nums[i])
                    max = nums[i];
                if (card[nums[i]])
                    return false;
                card[nums[i]] = true;
            }

        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] - min > 4)
                return false;
        }
        return true;
    }*/

    //排序方法   都不如 自己的不排序方法 哈哈
    bool isStraight(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int king = 0;
        for (int i = 0; i < nums.size()-1; i++)
        {
            if (nums[i] == 0)
                king++;
            else
            {
                if (nums[i] == nums[i + 1])
                    return false;
                if (nums[i + 1]-nums[i]==1 )
                    continue;
                else
                    king-= nums[i + 1] - nums[i]-1;
            }
        }
        return king >= 0;
    }
};
/*
int main()
{
    Solution s1;
    vector<int> test = { 10,11,0,12,6 };
    cout<<s1.isStraight(test);
    mytest();
}

void mytest() 在调用点之后，必须在调用点之前加一个函数原型(参数列表有类型就可以) 告诉编译器有这个函数
{
    cout << "this is my test" << endl;
}
*/