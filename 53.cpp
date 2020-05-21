#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    /*int search(vector<int>& nums, int target) {
        //�������飬����target��count++
        int count = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == target)
                count++;
        }
        return count;
    }*/
    //��û�и���ķ����������ʱ�临�Ӷ���O(n)
    //�Ѿ�֪��������������  ��ϸ����   �������û��ʲô����  ����˳�����  ʱ�临�Ӷ�Ҳ��O(n)
    /*int search(vector<int>& nums, int target) {
        //�������飬����target��count++
        if (nums.empty())
            return 0;
        int count = 0;
        int iterator = 0;
        while (iterator<nums.size()&&nums[iterator] < target)
            iterator++;
        while (iterator < nums.size()&&nums[iterator] == target)
        {
            count++;
            iterator++;
        }
        return count;
    }*/
    //�ܲ��ܶ��ֲ��ң�
    //���ö��ֲ��ң�����߽���ұ߽�
    //�𱻱��˵�˼·����
    //����ʹ���һ���ƽ������⣬(l+r)/2����������ȡ����Ե�ʣ���Ȼ��
    int search(vector<int>& nums, int target) {
        //���ζ��ֲ�������λ��߽����
        if (nums.empty())
            return 0;
        int low = 0, high = nums.size() - 1;
        int mid=0;
        while (low < high)
        {
            mid = (low + high) / 2;
            if (nums[mid] < target)
            {
                low = mid + 1;
            }
            else if (nums[mid] > target)
            {
                high = mid - 1;
            }
            else
            {
                //mid�����ֵ���target
                high = mid;  //����ƽ�
            }
        }
        if (nums[low] != target)
            return 0;
        int x = low;
        high = nums.size() - 1;
        while (low < high)
        {
            mid = (low + high+1) / 2;
            if (nums[mid] < target)
            {
                low = mid + 1;
            }
            else if (nums[mid] > target)
            {
                high = mid - 1;
            }
            else
            {
                //mid�����ֵ���target
                low = mid;  //���ұƽ�  ����ƽ�����һ������   ����  4  5 ����4
            }
        }
        return high - x + 1;
    }

};

/*int main()
{
    vector<int> test = { 5,7,7,8,8,10 };
    Solution s1;
    cout<<s1.search(test, 8);
}*/