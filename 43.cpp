#include<iostream>
#include<vector>
#include<string>
using namespace std;


class Solution {
public:
    //1-n֮���ж��ٸ�1
    //���÷��εķ������ԣ��̶�һ������ʣ�µ�����ʼ��

    //�������뵽���ǣ���һ���������м���1  ʹ��%10�����ˣ���1��n   ���ǳ�ʱ  ������
    /*
    int countDigitOne(int n) {
        int result = 0;
        for (int i = 0; i <= n; i++)
        {
            result += calculate1(i);
        }
        return result;
    }

    int calculate1(int n)
    {
        int result = 0;
        while (n != 0)
        {
            if (n % 10 == 1)
                result++;
            n = n / 10;
        }
        return result;
    }*/
    //����������������ϵ�˼������ 
    //�����ִ���һ����λ��λ������    ��ϸ����
    //���˴𰸣��о�����ѧ   Ϊʲô��û�п��ǽ�λ�����⣿������
    //�����ˣ����ϵĻ��ֺ�����!!!!!!!!!
    //�˵���first������first+1 ��������ʵ�������Ž�λ
    /*
    int countDigitOne(int n) {
        int result = 0;
        if (n <= 0)
            return result;
        vector<int> data;
        int copy = n;
        while (n!=0)
        {
            data.push_back(n%10);
            n = n / 10;
        }
        result = countDigitOne(data, copy);
        return result;
    }
    int countDigitOne(vector<int>& data,int n)
    {
        int result = 0;
        //��21345Ϊ��
        //���ȿ�����λ��1�����
        if (n == 0)
            return 0;
        if (n < 10)
            return 1;
        if (data.back() > 1)
        {
            result = pow(10, data.size() - 1);
        }
        else if(data.back()==1)
        {
            result = n - pow(10, data.size() - 1) + 1;
        }
        //Ȼ��������λΪ1��������ֳ����� [10000��19999]��[1346,9999]U[20000,21345]
        result += data.back() * (data.size() - 1) * pow(10, data.size() - 2);

        //Ȼ���ٿ���һ��1-1345֮���
        int withhigh = n - data.back() * pow(10, data.size() - 1);
        data.pop_back();
        return result + countDigitOne(data, withhigh);
    }*/

    //�����Ǹ�˼·û�����⣬����д�����Ǻܺÿ�
    int countDigitOne(int n) {
        if (n <= 0)
            return 0;
        if (n < 10)
            return 1;
        int result = 0;
        string numstring = to_string(n);
        //�ȿ�����λΪ1�����
        if (numstring[0] - 48 > 1)
        {
            result += pow(10, numstring.length() - 1);
        }
        else if (numstring[0] - 48 == 1)
        {
            result += n - pow(10, numstring.length() - 1) + 1;
        }
        //Ȼ��������λ��Ϊ1�����   ���ﲻ����ȥ����λ�������
        result += (numstring[0] - 48) * (numstring.length() - 1) * pow(10, numstring.length() - 2);

        //�����ȥ����λ������
        result += countDigitOne(n - (numstring[0] - 48) * pow(10, numstring.length() - 1));
        return result;
    }
};

/*int main()
{
    Solution s1;
    cout << s1.countDigitOne(1011) << endl;
}*/