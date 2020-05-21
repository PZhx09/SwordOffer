#include<iostream>
#include<vector>
using namespace std;
//同一个问题，但是范围变大了
//如果还是使用动态规划，从下向上，应该也是可以的，但是要考虑很多问题-->int越界、取模  取模的个数   很复杂
//使用贪婪算法好了
//qumo
class Solution {
public:
    int cuttingRope(int n) {
        if (n <= 2)
            return 1;
        if (n == 3)
            return 2;
        long result = 1;
        while (n >= 5)
        {
            result = result * 3 % 1000000007;
            n = n - 3;
        }
         result = result* n % 1000000007;
        return result;
    }
};

/*int main()
{
    Solution s1;
    cout<<s1.cuttingRope(120)<<endl;
}*/