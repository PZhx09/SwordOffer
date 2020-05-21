#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


class Solution {
public:
    //��̬�滮
    /*int maxSubArray(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        if (nums.size() == 1)
            return nums[0];
        int** matrix = new int*[nums.size()];
        for (int i = 0; i < nums.size(); i++)
            matrix[i] = new int[nums.size()];
        int max = nums[0];
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                matrix[i][j] = matrix[i - 1][j] + nums[i];
                max = max>matrix[i][j]?max: matrix[i][j];
            }
            matrix[i][i] = nums[i];
            max = max > matrix[i][i] ? max : matrix[i][i];
        }
        return max;
    }*/
    //�г����е��������
    //����ʱ�临�Ӷȳ���  ������O(n2)
    /*int maxSubArray(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        if (nums.size() == 1)
            return nums[0];
        int** matrix = new int* [nums.size()];
        for (int i = 0; i < nums.size(); i++)
            matrix[i] = new int[nums.size()];

        for (int i = 0; i < nums.size(); i++)
        {
            matrix[i][i] = nums[i];
            for (int j = i+1; j < nums.size(); j++)
            {
                matrix[i][j] = matrix[i][j - 1] + nums[j];
            }
            
        }
        int max = nums[0];
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i; j < nums.size(); j++)
                max = max > matrix[i][j] ? max : matrix[i][j];
        }
        return max;
    }*/
    //�������ұ���������ۼƺ�Ϊ���������κ�������������С����������������֮���max�Ƚ�


    //�����Ҳ�е㶯̬�滮��˼�롣
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        if (nums.size() == 1)
            return nums[0];
        int max = INT32_MIN;//����
        int sum = 0;//�ۼƺ�
        for (int i = 0; i < nums.size(); i++)
        {
            if (sum < 0)
                sum = 0;
            sum = sum + nums[i];
            max = max > sum ? max : sum;
        }
        return max;
    }
};

/*int main()
{
    Solution s1;
    vector<int> nums = { -1,-2};
    cout<<s1.maxSubArray(nums)<<endl;
}*/