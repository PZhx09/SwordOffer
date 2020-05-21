#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
    //好的方法还没想出来，先来个暴力算法吧
    /*int singleNumber(vector<int>& nums) {
        map<int, int> data;
        for (int i = 0; i < nums.size(); i++)
            data[nums[i]]++;
        for (int i = 0; i < nums.size(); i++)
        {
            if (data[nums[i]] == 1)
                return nums[i];
        }
        return -1;
    }*/

    //3n+1  就没办法用异或了
    //不妨想一想3n+1的性质   按照位加一起，能被3整除说明那个“1”这位是0，否则是1
    //符号位的问题  没必要考虑  因为都是在补码上做的  你最后的ans不也是补码么
    int singleNumber(vector<int>& nums) {
        int result = 0;
        int bit[32] = { 0 };
        for (int i = 0; i < nums.size(); i++)
        {
            unsigned int indexBit = 1;
            for (int j = 0; j < 32; j++)
            {
                if (nums[i] & indexBit)
                    bit[j]++;
                indexBit = indexBit << 1;//这里注意indexbit并不是数组下标例如100 应该存在bit[2]但是  这里indexBit是4   leetcode不支持负值左移   这里要转化成无符号整数

            }
        }
        for (int i = 31; i >= 0; i--)
        {
            //移位的时候注意
            result = result << 1;
            result += bit[i] % 3;
           
        }


        return result;
    }
};

/*int main()
{
    vector<int> test = { 9,1,7,9,7,9,7 };
    Solution s1;
    cout<<s1.singleNumber(test);
}*/