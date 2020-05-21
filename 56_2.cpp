#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
    //�õķ�����û������������������㷨��
    /*int singleNumber(vector<int>& nums) {
        map<int, int> data;
        for (int i = 0; i < nums.size(); i++)
            data[nums[i]]++;
        for (int i = 0; i < nums.size(); i++)
        {
            if (data[nums[i]] == 1)
                return nums[i];
        }
        return -1;
    }*/

    //3n+1  ��û�취�������
    //������һ��3n+1������   ����λ��һ���ܱ�3����˵���Ǹ���1����λ��0��������1
    //����λ������  û��Ҫ����  ��Ϊ�����ڲ���������  ������ans��Ҳ�ǲ���ô
    int singleNumber(vector<int>& nums) {
        int result = 0;
        int bit[32] = { 0 };
        for (int i = 0; i < nums.size(); i++)
        {
            unsigned int indexBit = 1;
            for (int j = 0; j < 32; j++)
            {
                if (nums[i] & indexBit)
                    bit[j]++;
                indexBit = indexBit << 1;//����ע��indexbit�����������±�����100 Ӧ�ô���bit[2]����  ����indexBit��4   leetcode��֧�ָ�ֵ����   ����Ҫת�����޷�������

            }
        }
        for (int i = 31; i >= 0; i--)
        {
            //��λ��ʱ��ע��
            result = result << 1;
            result += bit[i] % 3;
           
        }


        return result;
    }
};

/*int main()
{
    vector<int> test = { 9,1,7,9,7,9,7 };
    Solution s1;
    cout<<s1.singleNumber(test);
}*/