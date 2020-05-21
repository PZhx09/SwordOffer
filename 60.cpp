#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    //n�����ӣ�ȡֵ��ΧӦ����[n,6n]    ˫�߶��ǰ�����
    //���ܳ��ֵ������pow(6,n)

    //�ȱ��빫ʽ��   ����������ɾ���
    //ֱ��ȫ��������������˵   ȫ����  10/11   ���һ����ʱ
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

        if (iterator == 0)//��������
        {
            ans[sum - n]++;
            return;
        }
        for (int i = 1; i <= 6; i++)
        {
            sum1ton(sum+i,n ,iterator - 1, ans);
        }
    }

    //����Ӧ���Ƕ�̬�滮   ����ʱ����
};
/*
int main()
{
    Solution s1;
    vector<double> test=s1.twoSum(11);
    for (int i = 0; i < test.size(); i++)
        cout << test[i] << endl;
}*/