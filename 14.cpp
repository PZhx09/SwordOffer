#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    //ÿ������ �Ƕ�2������Ӱ��ģ������Ҿ��û��Ƕ�̬�滮�㷨���������һЩ
    //�ͱ������⻹����Щ�����
    //������˼�ķֽ⣬��һ��������ֽ��С���⣬ͨ��С����ϳɴ���������Ž⡣
    int cuttingRope(int n) {
        if (n < 2)
            return 1;
        if (n == 3)
            return 2;
        int *product = new int[n + 1];
        product[0] = 0;
        product[1] = 1;
        product[2] = 2;//����Ϊ2����ֵ�϶���1����������������ʱ����2        ��Ϊ��ĿҪ������һ�Σ�����2��3���Ǽ�֮�󷴶���С
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
