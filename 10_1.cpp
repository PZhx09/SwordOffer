#include<iostream>
using namespace std;

/*class Solution {
public:
    //ֱ�Ӹ���쳲�������������д������ʱ������  fib(n - 1) + fib(n - 2)
    //�ռ任ʱ�䣬��һ������������  ��¼쳲�������ֵ
    //ע��ȡģ����
    //�����õݹ�ķ�������  ʹ�ø�������ӿ죬�����ظ����㣬����ֱ��ʹ��ѭ������
    int fibResult[101] = {0,1};
    int fib(int n) {
        if (n == 0)
            return 0;
        if (fibResult[n] != 0)
            return fibResult[n];

        int result = (fib(n - 1) + fib(n - 2)) % 1000000007;
        fibResult[n] = result;

        return result;

    }
};*/

class Solution {
public:
    int fib(int n) {
        int result[] = { 0,1 };
        if (n < 2)
            return result[n];
        int fibone = 0;  //n-2
        int fibtwo = 1;  //n-1
        int fibn = 0;
        int i = 1;
        while (i < n)
        {
            fibn = (fibone + fibtwo) % 1000000007;
            fibone = fibtwo;
            fibtwo = fibn;
            i++;
        }
        return fibn;

    }
};
/*int main()
{
    Solution s1;
    cout << s1.fib(8);
//    for (int i = 0;i < 20; i++)
//        cout << s1.fib(i)<<endl;
}*/