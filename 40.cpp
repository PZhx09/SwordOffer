#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


class Solution {
public:
    //ע�����������k<=0����null  k>���鳤�ȣ�������������
    //��򵥾����뵽�ģ������귵��  ʱ�临�Ӷ�ΪO(nlodn)
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
    //2�����ÿ��ŷָ��˼���ҳ���k�������С�������Ǿ��ǽ��
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
                index = partition(arr, start, end);//�������ص㣬Ҫ���ϵ���С��Χ����������������
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