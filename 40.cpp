#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


class Solution {
public:
    //注意特殊情况，k<=0返回null  k>数组长度，返回整个数组
    //最简单就能想到的，排序完返回  时间复杂度为O(nlodn)
    /*vector<int> getLeastNumbers(vector<int>& arr, int k) {
        if (k >= arr.size())
            return arr;
        if ( k <= 0)
            return vector<int>();
        vector<int> sorted = arr;
        sort(sorted.begin(), sorted.end());
        vector<int> result(sorted.begin(), sorted.begin() + k);
        return result;
    }*/
    //2、利用快排分割的思想找出第k大的数，小于他的那就是结果
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        if (k >= arr.size())
            return arr;
        if (k <= 0)
            return vector<int>();
        int index = -1;
        int start = 0, end = arr.size() - 1;
        while (index != k - 1)
        {
            if (index < k - 1)
            {
                start = index + 1;
                index = partition(arr, start, end);
            }
            else
            {
                end = index - 1;
                index = partition(arr, start, end);//这里是重点，要不断地缩小范围！！！！！！！！
            }
        }
        vector<int> result(arr.begin(), arr.begin() + k);
        return result;
    }
    int partition(vector<int>& arr, int start, int end)
    {
        int cursor = arr[start];
        int i = start, j = end;
        while (i < j)
        {
            while (arr[j] >= cursor &&i < j)
                j--;
            arr[i] = arr[j];
            while (arr[i] <= cursor &&i < j)
                i++;
            arr[j] = arr[i];
        }
        arr[i] = cursor;
        return i;
    }
};
/*int main()
{
    Solution s1;
    vector<int> test1= {1, 3, 4, 7, 9, 2, 5, 8};
    vector<int> result=s1.getLeastNumbers(test1,3);
    cout << result.size() << endl;
}*/