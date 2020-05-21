#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    //����һ����򵥵ķ�����˳�����
    /*int missingNumber(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++)
            if (i != nums[i])
                return i;
        return nums.size();
    }*/
    //�ö��ֲ�������
    int missingNumber(vector<int>& nums) {
        int low = 0, high = nums.size();//����high��ȡֵ��������high��size-1  ���Ҫ�ж�һ���ǲ���ǰ�涼û��ȱ����
        int mid = 0;
        while (low<high)
        {
            mid = (low + high) / 2;
            if (nums[mid] == mid)
            {
                low = mid+1;
            }
            else
            {
                high = mid;
            }
        }

        return low;
    }
};

/*int main()
{
    vector<int> test = {0,1,3};
    Solution s1;
    cout << s1.missingNumber(test);
}*/