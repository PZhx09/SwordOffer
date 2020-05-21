#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    //n个骰子，取值范围应该是[n,6n]    双边都是包含的
    //可能出现的情况是pow(6,n)

    //先别想公式了   排列组合忘干净了
    //直接全排列先做出来再说   全排列  10/11   最后一个超时
    vector<double> twoSum(int n) {
        vector<double> ans;
        ans.resize(5*n+1);
        int sum = 0;
        sum1ton(sum, n,n, ans);
        double base = pow(6, n);
        for (int i = 0; i < ans.size(); i++)
            ans[i] /= base;
        return ans;
    }
    void sum1ton(int sum,int n,int iterator, vector<double>& ans)
    {

        if (iterator == 0)//遍历完了
        {
            ans[sum - n]++;
            return;
        }
        for (int i = 1; i <= 6; i++)
        {
            sum1ton(sum+i,n ,iterator - 1, ans);
        }
    }

    //这题应该是动态规划   先暂时搁置
};
/*
int main()
{
    Solution s1;
    vector<double> test=s1.twoSum(11);
    for (int i = 0; i < test.size(); i++)
        cout << test[i] << endl;
}*/