#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;



//自定义一个小于函数来进行排序！！！！！
//两个数长度相等很好想
//但是如果长度不相等呢？

bool comp(const int& a, const int& b)//小于函数
{
    //比较函数   这里我使用的找规律  找到比较的规律然后返回  
    /*string sa = to_string(a);
    string sb = to_string(b);
    int i = 0;
    //对比时，如果发现不等就返回，如果一直相等那么就返回长的
    while (i < sa.length() || i < sb.length())
    {
        if (sa[i % sa.length()] > sb[i % sb.length()])
            return false;
        else if (sa[i % sa.length()] < sb[i % sb.length()])
            return true;
        i++;
    }
    return sa.length() > sb.length() ? true : false;*/

    //但是还有另一种更为直接的方法，哪个放前面小，那说明哪个数是小的   简单明了！！！！！！！！！！！！！！！！！！！
    string afirst = to_string(a)+ to_string(b);
    string bfirst = to_string(b)+ to_string(a);
    return afirst < bfirst ? true : false;
}

class Solution {
public:
    //对容器中的数字进行“排序”
    string minNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end(), comp);
        string ans;
        for (int i = 0; i < nums.size(); i++)
        {
            ans += to_string(nums[i]);
        }
        return ans;
    }

};
/*int main()
{
    Solution s1;
    cout << comp(12,122) << endl;
    vector<int> test = { 3,30,34,5,9 };
    cout << s1.minNumber(test) << endl;
}*/