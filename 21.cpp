#include<iostream>
#include<vector>
using namespace std;

//��һ����������ʱ������  
//�㷨Ӧ���ǶԵģ����Կ�����ʱ�临�Ӷȵ�����
//���ﻳ����push_back��erase��������������
/*class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int i = 0;
        int j = nums.size();
        while (i != nums.size()&&i!=j)
        {
            if (nums[i] % 2 == 0)
            {
                int tmp = nums[i];
                nums.erase(nums.begin() + i);
                nums.push_back(tmp);
                j--;
                continue;
            }
            i++;
        }
        return nums;
    }
};*/
class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        if (nums.size() == 0)
            return nums;
        int i = 0;
        int j = nums.size()-1;
        //����i��j���ƶ���������һ��һ��
        //iָ�������Զ����jָ��ż���Զ���ǰ
        while (i != j)
        {
            if (nums[i] % 2 == 1)
            {
                i++;
                continue;
            }
            int tmp = nums[i];
            nums[i] = nums[j];
            nums[j] = tmp;
            j--;
        }
        return nums;
    }
};
/*int main()
{
    Solution s1;
    vector<int> nums = { 1,2,3,4 };
    s1.exchange(nums);
}*/