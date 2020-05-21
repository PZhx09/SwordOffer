#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

class Solution {
public:
    //���ַ���
    //1�����ù�ϣ��
    /*int majorityElement(vector<int>& nums) {
        map<int, int> numdata;
        if (nums.size() == 1)
            return nums[0];
        int halfLength = nums.size() / 2;
        for (int i = 0; i < nums.size();i++)
        {
            numdata[nums[i]]++;
            if (numdata[nums[i]] > halfLength)
                return nums[i];

        }
        return -1;
    }*/
    //2����������
    //ռ�����ϣ���ô˵��һ�����м�
    /*int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() / 2];
    }*/
    //3��ռ���������֣�һ������������
    //���
    /*int majorityElement(vector<int>& nums) {

        int occurTime = 1;
        int result = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            if (result == nums[i])
                occurTime++;
            else
                occurTime--;
            if (occurTime == 0)
            {
                result = nums[i];
                occurTime = 1;
            }
        }

        return result;
    }*/
    //4�����������ÿ��������˼�룬�ҵ���λ���Ϳ�����  ʱ�临�Ӷ�ΪO(n)   ���˼�����Ҫ  ��Ϊ�������ÿ�������ָ��˼����O(n)�ĸ��Ӷ��ҵ���k�������
    int majorityElement(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        int middle = nums.size() / 2;
        int index = -1;
        int start = 0, end = nums.size() - 1;
        while(index!=middle)
        {
            if (index < middle)
            {
                start = index + 1;
                index = partition(nums, start, end);
            }
            else
            {
                end = index - 1;
                index = partition(nums, start, end);
            }
        }
        return nums[index];
    }
    int partition(vector<int>& nums, int start, int end)
    {
        int cursor = nums[start];
        int i = start, j = end;
        while (i < j)
        {
            while (nums[j] >= cursor && i < j)
                j--;
            nums[i] = nums[j];

            while (nums[i] <= cursor && i < j)
                i++;
            nums[j] = nums[i];
        }
        nums[i] = cursor;
        return i;
    }
};

/*int main()
{
    Solution s1;
    vector<int> nums = { 4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,4,5};
    cout << s1.majorityElement(nums)<<endl;
}*/