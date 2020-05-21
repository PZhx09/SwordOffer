#include<iostream>
#include<vector>
#include<map>
#include<set>
using namespace std;


class Solution {
public:
    //����map����   keyװֵ��valueװ����  ʱ�����ܺܲ�
    /*vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        map<int, int> data;
        for (int i = 0; i < nums.size(); i++)
        {
            if (data.find(target - nums[i]) != data.end())
            {
                ans.push_back(target - nums[i]);
                ans.push_back( nums[i]);
                return ans;
            }
            data[nums[i]] = i;
        }
        return ans;
    }*/
    //��set��һ��
    //set����û������   ʱ�临�ӶȺͿռ临�Ӷȶ���O(n)
    /*vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        set<int> data;
        for (int i = 0; i < nums.size(); i++)
        {
            if (data.find(target - nums[i]) != data.end())
            {
                ans.push_back(target - nums[i]);
                ans.push_back(nums[i]);
                return ans;
            }
            data.insert(nums[i]);
        }
        return ans;
    }*/
    //����set����û�����õ����������������
    //����˫ָ�뷨
    vector<int> twoSum(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        int sum = 0;
        /*while (nums[low] + nums[high] != target)
        {
            if (nums[low] + nums[high] > target)
                high--;
            else
                low++;
        }*/ //ѧѧ���˵�д��
        while (low < high)
        {
            sum = nums[low] + nums[high];
            if (sum == target)
            {
                break;
            }
            if (sum < target)
                low++;
            else
                high--;
        }

        return vector<int>{nums[low],nums[high]};
    }
};

/*int main()
{
    map<int, int> data;
}*/