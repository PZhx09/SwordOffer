#include<iostream>
#include<vector>
using namespace std;

/*class Solution {
public:
    //����һ����������  �ܺ����������ʱ�临�Ӷ���O(n)
    int minArray(vector<int>& numbers) {
        if (numbers[0] < numbers.back())  //����ӿ��ٶ�
            return numbers[0];
        int min= numbers[0];
        for (int i = 1; i < numbers.size(); i++)
        {
            if (min <= numbers[i])
                continue;
            else {
                min = numbers[i];
                break;
            }
        }
        return min;
    }
};*/


class Solution {
public:
    //�й����򣬺����׾��뵽���ֵķ���   
    //�ѵ���ȷ���߽�
    int minArray(vector<int>& numbers) {
        if (numbers[0] < numbers.back())  //����ӿ��ٶ�
            return numbers[0];
        return quickfind(numbers, 0, numbers.size() - 1);
    }
    int quickfind(vector<int>& numbers,int left, int right)
    {
        if (right  == left)
            return numbers[right];
        if (right - left == 1)
            return numbers[right] ;
        int mid = (left + right) / 2;
        if (numbers[left] < numbers[mid])
            return quickfind(numbers, mid, right);
        else if (numbers[left] > numbers[mid])
            return quickfind(numbers, left, mid);
        else
            return quickfind(numbers, mid, right) < quickfind(numbers, left, mid) ? quickfind(numbers, mid, right) : quickfind(numbers, left, mid);
    }
};

/*int main()
{
    Solution s1;
    vector<int> numbers = {1 };
    cout << s1.minArray(numbers)<<endl;
}*/