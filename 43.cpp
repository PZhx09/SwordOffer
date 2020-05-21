#include<iostream>
#include<vector>
#include<string>
using namespace std;


class Solution {
public:
    //1-n之间有多少个1
    //采用分治的方法试试，固定一个数，剩下的数开始动

    //最容易想到的是，求一个数里面有几个1  使用%10就行了，从1求到n   但是超时  不可行
    /*
    int countDigitOne(int n) {
        int result = 0;
        for (int i = 0; i <= n; i++)
        {
            result += calculate1(i);
        }
        return result;
    }

    int calculate1(int n)
    {
        int result = 0;
        while (n != 0)
        {
            if (n % 10 == 1)
                result++;
            n = n / 10;
        }
        return result;
    }*/
    //接下来用用排列组合的思想试试 
    //这里又存在一个进位退位的问题    仔细想想
    //看了答案，感觉很玄学   为什么答案没有考虑借位的问题？？？？
    //考虑了，书上的划分很巧妙!!!!!!!!!
    //乘的是first而不是first+1 ，这里其实就隐含着借位
    /*
    int countDigitOne(int n) {
        int result = 0;
        if (n <= 0)
            return result;
        vector<int> data;
        int copy = n;
        while (n!=0)
        {
            data.push_back(n%10);
            n = n / 10;
        }
        result = countDigitOne(data, copy);
        return result;
    }
    int countDigitOne(vector<int>& data,int n)
    {
        int result = 0;
        //以21345为例
        //首先考虑首位是1的情况
        if (n == 0)
            return 0;
        if (n < 10)
            return 1;
        if (data.back() > 1)
        {
            result = pow(10, data.size() - 1);
        }
        else if(data.back()==1)
        {
            result = n - pow(10, data.size() - 1) + 1;
        }
        //然后考虑其他位为1的情况，分成两组 [10000，19999]和[1346,9999]U[20000,21345]
        result += data.back() * (data.size() - 1) * pow(10, data.size() - 2);

        //然后再考虑一下1-1345之间的
        int withhigh = n - data.back() * pow(10, data.size() - 1);
        data.pop_back();
        return result + countDigitOne(data, withhigh);
    }*/

    //上面那个思路没有问题，但是写法不是很好看
    int countDigitOne(int n) {
        if (n <= 0)
            return 0;
        if (n < 10)
            return 1;
        int result = 0;
        string numstring = to_string(n);
        //先考虑首位为1的情况
        if (numstring[0] - 48 > 1)
        {
            result += pow(10, numstring.length() - 1);
        }
        else if (numstring[0] - 48 == 1)
        {
            result += n - pow(10, numstring.length() - 1) + 1;
        }
        //然后考虑其他位置为1的情况   这里不考虑去掉首位后的数字
        result += (numstring[0] - 48) * (numstring.length() - 1) * pow(10, numstring.length() - 2);

        //最后考虑去掉首位后的情况
        result += countDigitOne(n - (numstring[0] - 48) * pow(10, numstring.length() - 1));
        return result;
    }
};

/*int main()
{
    Solution s1;
    cout << s1.countDigitOne(1011) << endl;
}*/