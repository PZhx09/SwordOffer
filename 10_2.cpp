#include<iostream>
using namespace std;

class Solution {
public:
    //������̨������
    //��ʵ����쳲�������������
    //�����n�ף�ֻ�������������1�׵�n����2�׵�n
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