#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    //感觉很像子数组之和最大的那一道题
    //最简单的  暴力便利    中间剪枝   性能居然意外的好 哈哈   
    /*vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> ans;

        for (int i = 1; i < target; i++)
        {
            int sum = 0;
            for (int j = i; j < target; j++)
            {
                sum += j;
                if (sum == target)
                {
                    vector<int> data;
                    for (int k = i; k <= j; k++)
                        data.push_back(k);
                    ans.push_back(data);
                    break;
                }
                else if (sum > target)
                    break;

            }
        }
        return ans;
    }*/
    //双指针  双百   比上面的好一个数量级
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> ans;
        if (target < 3)
            return ans;
        int low = 1, high = 2;
        int sum = 3;
        while (low < target / 2 + 1)
        {
            if (sum == target)
            {
                vector<int> data;
                for (int k = low; k <= high; k++)
                    data.push_back(k);
                ans.push_back(data);
                sum -= low;
                low++;
                
            }
            else if (sum < target)
            {
                high++;
                sum += high;
            }
            else
            {
                sum -= low;
                low++;
            }
        }
        return ans;
    }

};

/*int main()
{
    Solution s1;
    s1.findContinuousSequence(9);
}*/