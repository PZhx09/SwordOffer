#include<iostream>
#include<vector>
#include<map>
using namespace std;



class Solution {
public:
    //��һ�뷨:ά������������ÿ�α�����һ���µ�Ԫ�ؽ��бȽϣ��������ȼ�����������ʾ�ض����¸��滻����
    //���������12321  ����ô��3���û�����

    //�ڶ��뷨�����ø������ݽṹmap �ܼ�  ����ʱ�临�Ӷ�O(n)  ���ǿռ临�Ӷ�Ҳ��O(n)   
    //�����ȷ  ʱ��5.46  �ռ�100  
    /*vector<int> singleNumbers(vector<int>& nums) {
        vector<int> ans;
        map<int, int> data;
        for (int i = 0; i < nums.size(); i++)
            data[nums[i]]++;
        for (int i = 0; i < nums.size(); i++)
        {
            if (data[nums[i]] == 1)
                ans.push_back(nums[i]);
        }
        return ans;
    }*/
    //Ӧ����ʹ�����  ���忴����������
    //�������飬���һ�� ���յõ�a^b  ����a��b��ô���뿪�أ�
    //��a��b���뵽������ͬ�������о�����

    //���˽�ָ  ˼·û���⣬���Ǵ�����ڸ���

    /*
    vector<int> singleNumbers(vector<int>& nums) {
        vector<int> ans;
        int data=0;
        int num1 = 0, num2 = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            data = data ^ nums[i];
        }
        int indexOfOne = getFirstOne(data);

        for (int i = 0; i < nums.size(); i++)
        {
            if (isBitOne(nums[i], indexOfOne))
            {
                num1 = num1 ^ nums[i];
            }
            else
            {
                num2 = num2 ^ nums[i];
            }
        }
        return vector<int>{num1, num2};
    }

    int getFirstOne(int data)
    {
        //���ص�һ��1���ڵ�λ������   110  ����1   111����0  ����
        int indexOfOne = 0;
        while (!(data & 1))
        {
            indexOfOne++;
            data = data >> 1;
        }
        return indexOfOne;
    }
    bool isBitOne(int num, int index)
    {
        num = num >> index;
        return num & 1;
    }
    */
    //�������ķ���  �Ż���λ����
    /*vector<int> singleNumbers(vector<int>& nums) {
        int data = 0;
        int num1 = 0, num2 = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            data = data ^ nums[i];
        }
        int indexOfOne =0;
        while (!(data & 1))
        {
            indexOfOne++;
            data=data >> 1;
        }
            

        for (int i = 0; i < nums.size(); i++)
        {
            if ((nums[i]>>indexOfOne)&1)
            {
                num1 = num1 ^ nums[i];
            }
            else
            {
                num2 = num2 ^ nums[i];
            }
        }
        return vector<int>{num1, num2};
    }*/
    //�������۵Ĳ���  ���Ｖ��
    vector<int> singleNumbers(vector<int>& nums) {
        int data = 0;
        int num1 = 0, num2 = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            data = data ^ nums[i];
        }
        int k = data & (-data);
        for (int i = 0; i < nums.size(); i++)
        {
            if (k & nums[i])
                num1 ^= nums[i];
            else
                num2 ^= nums[i];
        }
        return vector<int>{num1, num2};
    }
};


/*int main()
{
    int a = 4;
    int b = 3;
    int c = a ^ b;
    Solution s1;
}*/