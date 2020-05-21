#include<iostream>
using namespace std;

class Solution {
public:
    //青蛙跳台阶问题
    //其实就是斐波那契数列问题
    //到达第n阶，只有两种情况，跳1阶到n，跳2阶到n
    int fibResult[101] = { 1,1,2 };
    int numWays(int n) {
        if (fibResult[n] != 0)
            return fibResult[n];

        int result = (numWays(n - 1) + numWays(n - 2)) % 1000000007;
        fibResult[n] = result;

        return result;

    }
};
/*int main()
{
    Solution s1;
    cout << s1.numWays(7);
//    for (int i = 0;i < 20; i++)
//        cout << s1.fib(i)<<endl;
}*/