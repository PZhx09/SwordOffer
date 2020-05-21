#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    
    /*int findNthDigit(int n) {
        //数字num的位数是log(num),按照这个思路找到n落在的数字，然后再求好了\
        //重点1、位数转换
        //2、从0开始计数
        //超时，怀疑是 累计bitOfNum处浪费的时间太多
        //思路对，但是超时，找一找数字之间的规律好了
        if (n == 0)
            return 0;

        int num = 0;
        int bitOfNum = 0;
        while (bitOfNum < n)
        {
            num++;
            bitOfNum += log(num)/log(10) + 1;
        }
        //这时说明  n落在num中
        n = n - (bitOfNum - log(num)/log(10) - 1)-1;
        return to_string(num)[n]-48;

    }*/
    //先判断是几位数，思路是对的可惜自己不相信自己
    //双百！！！相信自己
    //不要想着累计位数，一定范围内的数字位数是确定的，可以直接定位啊
    int findNthDigit(int n) {
        if (n < 10)
            return n;

        int numbit = 1;
        long long sumOfBit = 10;
        while (sumOfBit < n)
        {
            numbit++;
            sumOfBit += numbit*9*pow(10, numbit-1);     //这里需要注意sumOfbit很容易就越界了！！！！！  必须考虑
        }
        //这时说明  n是numbit位数字
        n = n - (sumOfBit - numbit * 9 * pow(10, numbit - 1));
        int num = pow(10, numbit - 1) + n / numbit;
        return to_string(num)[n%numbit]-48;

    }
};
/*int main()
{
    Solution s1;
    cout << s1.findNthDigit(75) << endl;
}*/
