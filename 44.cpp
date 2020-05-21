#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    
    /*int findNthDigit(int n) {
        //����num��λ����log(num),�������˼·�ҵ�n���ڵ����֣�Ȼ���������\
        //�ص�1��λ��ת��
        //2����0��ʼ����
        //��ʱ�������� �ۼ�bitOfNum���˷ѵ�ʱ��̫��
        //˼·�ԣ����ǳ�ʱ����һ������֮��Ĺ��ɺ���
        if (n == 0)
            return 0;

        int num = 0;
        int bitOfNum = 0;
        while (bitOfNum < n)
        {
            num++;
            bitOfNum += log(num)/log(10) + 1;
        }
        //��ʱ˵��  n����num��
        n = n - (bitOfNum - log(num)/log(10) - 1)-1;
        return to_string(num)[n]-48;

    }*/
    //���ж��Ǽ�λ����˼·�ǶԵĿ�ϧ�Լ��������Լ�
    //˫�٣����������Լ�
    //��Ҫ�����ۼ�λ����һ����Χ�ڵ�����λ����ȷ���ģ�����ֱ�Ӷ�λ��
    int findNthDigit(int n) {
        if (n < 10)
            return n;

        int numbit = 1;
        long long sumOfBit = 10;
        while (sumOfBit < n)
        {
            numbit++;
            sumOfBit += numbit*9*pow(10, numbit-1);     //������Ҫע��sumOfbit�����׾�Խ���ˣ���������  ���뿼��
        }
        //��ʱ˵��  n��numbitλ����
        n = n - (sumOfBit - numbit * 9 * pow(10, numbit - 1));
        int num = pow(10, numbit - 1) + n / numbit;
        return to_string(num)[n%numbit]-48;

    }
};
/*int main()
{
    Solution s1;
    cout << s1.findNthDigit(75) << endl;
}*/
