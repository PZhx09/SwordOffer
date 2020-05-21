#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    //思路   一个压栈序列，可能有很多不同的出栈序列
    //关键位置就是栈顶
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        vector<int> stack;
        int itrPush = 0;
        int itrPop = 0;
        while (itrPush < pushed.size())
        {
            stack.push_back(pushed[itrPush]);
            itrPush++;
            while (stack.back() == popped[itrPop])
            {
                itrPop++;
                stack.pop_back();
                if (stack.size() == 0)//这里也可能产生越界问题，当栈空的时候，while判断会访问不存在的内存地址！！！！
                    break;
            }
        }
        if (itrPop == itrPush)
            return true;
        else
            return false;
    }
};
/*int main()
{
    Solution s1;
    
    vector<int> pushed = { 1,2,3,4,5 };
    vector<int> poped = { 4,5,3,2,1 };
    cout<<s1.validateStackSequences(pushed, poped);
}*/