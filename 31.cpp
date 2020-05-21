#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    //˼·   һ��ѹջ���У������кܶ಻ͬ�ĳ�ջ����
    //�ؼ�λ�þ���ջ��
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
                if (stack.size() == 0)//����Ҳ���ܲ���Խ�����⣬��ջ�յ�ʱ��while�жϻ���ʲ����ڵ��ڴ��ַ��������
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