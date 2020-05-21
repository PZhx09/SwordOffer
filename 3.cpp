#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    //���ñ��������ķ�����һ�κ���
    //�����㷨��ʱ
    //�ռ任ʱ��   
    /*int findRepeatNumber(vector<int>& nums) {
        int *tmp;
        tmp=new int[nums.size()];
        for(int i=0;i<nums.size();i++)
        {
            if(tmp[nums[i]]==1)
                return nums[i];
            tmp[nums[i]]=1;
        }
        return 0;
    }*/
    //������ԭ���û��������ڲ������㷨
    int findRepeatNumber(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++)
        {
            if (i == nums[i])
                continue;
            int tmp = nums[i];
            nums[i] = -1;
            while (tmp != nums[tmp] && (nums[tmp] != -1))
            {
                int v = nums[tmp];
                nums[tmp] = tmp;
                tmp = v;
            }
            if (nums[tmp] == -1)
                nums[tmp] = tmp;
            else
                return tmp;
        }
        return 0;
    }
};

/*int main()
{
    Solution s1;
    vector<int> nums = { 2, 3, 1, 0, 2, 5, 3 };
    cout << s1.findRepeatNumber(nums);
}*/