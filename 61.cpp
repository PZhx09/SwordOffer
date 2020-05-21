#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    /*bool isStraight(vector<int>& nums) {
        //�ж��Ƿ�Ϊ˳��   ˳�ӿ϶�����5������һ�������
        //�����д����һ��д��ϡ��
        //��1�������飬�ҵ���С������.��2������������ǲ��Ƕ����Լ�5�ķ�Χ��   Ҫô������Ҫô��king��
        //��Ҫ�����ж��Ƿ��ظ�������   ����ǲ�����ʽ
        int min = 14;//���������ά��һ��max  �����Ļ�ֻҪ�ж�max-min�Ϳ�����
        bool card[14] = { false };
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != 0)
            {
                if(min > nums[i] )
                    min = nums[i];
                if (card[nums[i]])
                    return false;
                card[nums[i]] = true;
            }
                
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] - min > 4)
                return false;
        }
        return true;
    }*/
    //������ʽ  ��ѽⷨ?  �������Լ�ֻά��һ��min   ����һЩ
    /*bool isStraight(vector<int>& nums) {

        bool card[14] = { false };
        int min = 15, max = -1;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != 0)
            {
                if (min > nums[i])
                    min = nums[i];
                if (max < nums[i])
                    max = nums[i];
                if (card[nums[i]])
                    return false;
                card[nums[i]] = true;
            }

        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] - min > 4)
                return false;
        }
        return true;
    }*/

    //���򷽷�   ������ �Լ��Ĳ����򷽷� ����
    bool isStraight(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int king = 0;
        for (int i = 0; i < nums.size()-1; i++)
        {
            if (nums[i] == 0)
                king++;
            else
            {
                if (nums[i] == nums[i + 1])
                    return false;
                if (nums[i + 1]-nums[i]==1 )
                    continue;
                else
                    king-= nums[i + 1] - nums[i]-1;
            }
        }
        return king >= 0;
    }
};
/*
int main()
{
    Solution s1;
    vector<int> test = { 10,11,0,12,6 };
    cout<<s1.isStraight(test);
    mytest();
}

void mytest() �ڵ��õ�֮�󣬱����ڵ��õ�֮ǰ��һ������ԭ��(�����б������;Ϳ���) ���߱��������������
{
    cout << "this is my test" << endl;
}
*/