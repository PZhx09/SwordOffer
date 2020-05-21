#include<iostream>

using namespace std;

class Solution {
public:
    //��򵥵ķ�������1��ʼ  �����Ƿ�Ϊ������һֱ����n������ô�϶����ǵ�n��������
    //��������500/596��˵��˼·�ǶԵģ����ǳ���ʱ�临�Ӷ�
    /*
    int nthUglyNumber(int n) {
        int count = 0;
        int number = 1;
        while (count != n)
        {
            int tmp = number;
            while (tmp % 2 == 0)
                tmp = tmp / 2;
            while (tmp % 3 == 0)
                tmp = tmp / 3;
            while (tmp % 5 == 0)
                tmp = tmp / 5;
            if (tmp == 1)
            {
                count++;
            }
            number++;
        }
        return --number;
    }*/
    //�����϶��ǳ�����2��3��5�ó��ģ���ôֻҪ����n������������(����ķ�����Ҫ�Էǳ����������㣬�������Ҫ)
    int nthUglyNumber(int n) {
        if (n <= 1)
            return n;
        int* ugly = new int[n];
        ugly[0] = 1;
        int count = 1;
        int t2 = 0, t3 = 0, t5 = 0;
        int m2=0, m3=0, m5=0;
        while (count < n)
        {
            for (int i = t2; i < count; i++)
            {
                if (ugly[i] * 2 > ugly[count - 1])
                {
                    m2 = ugly[i] * 2;
                    break;
                }
                else
                {
                    t2++;
                }
            }
            for (int i = t3; i < count; i++)
            {
                if (ugly[i] * 3 > ugly[count - 1])
                {
                    m3 = ugly[i] * 3;
                    break;
                }
                else
                {
                    t3++;
                }
            }
            for (int i = t5; i < count; i++)
            {
                if (ugly[i] * 5 > ugly[count - 1])
                {
                    m5 = ugly[i] * 5;
                    break;
                }
                else
                {
                    t5++;
                }
            }
            int tmp = m2 < m3 ? m2 : m3;
            tmp = tmp < m5 ? tmp : m5;
            ugly[count] = tmp;
            count++;
        }
        return ugly[n - 1];
    }

};
/*int main()
{
    Solution s1;
    cout << s1.nthUglyNumber(10) << endl;
}*/