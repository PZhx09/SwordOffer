#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    //每步进行 是对2下面有影响的，所以我觉得还是动态规划算法更合情合理一些
    //和背包问题还是有些区别的
    //很有意思的分解，把一个大问题分解成小问题，通过小问题合成大问题的最优解。
    int cuttingRope(int n) {
        if (n < 2)
            return 1;
        if (n == 3)
            return 2;
        int *product = new int[n + 1];
        product[0] = 0;
        product[1] = 1;
        product[2] = 2;//长度为2返回值肯定是1，但是用做乘数的时候是2        因为题目要求必须剪一次，所以2和3都是剪之后反而变小
        product[3] = 3;
        for (int i = 4; i <= n; i++)
        {
            int max = 0;
            for (int j = 1; j <= i / 2; j++)
            {
                if (max < product[j] * product[i - j])
                    max = product[j] * product[i - j];
            }
            product[i] = max;
        }
        return product[n];

    }
};

/*int main()
{
    Solution s1;
    cout<<s1.cuttingRope(10) << endl;
}*/
