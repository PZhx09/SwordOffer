#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;



//�Զ���һ��С�ں������������򣡣�������
//������������Ⱥܺ���
//����������Ȳ�����أ�

bool comp(const int& a, const int& b)//С�ں���
{
    //�ȽϺ���   ������ʹ�õ��ҹ���  �ҵ��ȽϵĹ���Ȼ�󷵻�  
    /*string sa = to_string(a);
    string sb = to_string(b);
    int i = 0;
    //�Ա�ʱ��������ֲ��Ⱦͷ��أ����һֱ�����ô�ͷ��س���
    while (i < sa.length() || i < sb.length())
    {
        if (sa[i % sa.length()] > sb[i % sb.length()])
            return false;
        else if (sa[i % sa.length()] < sb[i % sb.length()])
            return true;
        i++;
    }
    return sa.length() > sb.length() ? true : false;*/

    //���ǻ�����һ�ָ�Ϊֱ�ӵķ������ĸ���ǰ��С����˵���ĸ�����С��   �����ˣ�������������������������������������
    string afirst = to_string(a)+ to_string(b);
    string bfirst = to_string(b)+ to_string(a);
    return afirst < bfirst ? true : false;
}

class Solution {
public:
    //�������е����ֽ��С�����
    string minNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end(), comp);
        string ans;
        for (int i = 0; i < nums.size(); i++)
        {
            ans += to_string(nums[i]);
        }
        return ans;
    }

};
/*int main()
{
    Solution s1;
    cout << comp(12,122) << endl;
    vector<int> test = { 3,30,34,5,9 };
    cout << s1.minNumber(test) << endl;
}*/