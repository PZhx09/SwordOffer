#include<iostream>
#include<string>
#include<set>
#include<map>
#include<vector>
using namespace std;

class Solution {
public:
    //使用两个辅助结构set好了，一个用于判断，一个用来保存只出现一次的
    /*char firstUniqChar(string s) {
        if (s.length() == 0)
            return ' ';
        set<char> judge;
        set<char> unique;
        char result = ' ';
        for (int i = 0; i < s.length(); i++)
        {
            if (judge.find(s[i]) == judge.end())
            {
                judge.insert(s[i]);
                unique.insert(s[i]);
            }
            else
                unique.erase(s[i]);
        }
        for (int i = 0; i < s.length(); i++)
        {
            if (unique.find(s[i]) != unique.end())
                return s[i];
        }
        return ' ';
    }*/
    //换一个辅助结构试试,因为map记录了顺序，所以只用遍历一遍
    /*char firstUniqChar(string s) {
        if (s.length() == 0)
            return ' ';
        set<char> judge;
        map<int,char> unique;
        char result = ' ';
        for (int i = 0; i < s.length(); i++)
        {
            if (judge.find(s[i]) == judge.end())
            {
                judge.insert(s[i]);
                unique.insert(pair<int,char>(i,s[i]));
            }
            else
                unique.erase(s.find(s[i]));
        }
        if (!unique.empty())
        {
            return unique.begin()->second;
        }
        return ' ';
    }*/
    //别把问题想的太困难，统计次数试试
    //这样反而要比用set快
    /*char firstUniqChar(string s) {
        if (s.length() == 0)
            return ' ';
        map<char, int> unique;
        for (int i = 0; i < s.length(); i++)
        {
            unique[s[i]]++;
        }
        if (!unique.empty())
        {
            for (int i = 0; i < s.length(); i++)
            {
                if (unique[s[i]] == 1)
                    return s[i];
            }
        }
        return ' ';
    }*/
    //前面的方法都要遍历两次字符串，并且都要用到hash
    //仔细想想，一共只有128个字符，那么直接分配一个128的数组不就行了，而且数组-1表示没出现，-2表示有重复，>0表示在字符串中的位置。
    //最快的方法！！！！！！
    //int和char可以自由转换
    char firstUniqChar(string s) {
        if (s.length() == 0)
            return ' ';
        vector<int> ascii(128, -1);
        for (int i = 0; i < s.length(); i++)
        {
            if (ascii[s[i]] == -1)
                ascii[s[i]] = i;
            else
                ascii[s[i]] = -2;
        }
        int resultIndex = s.size();
        for (int i = 1; i < 128; i++)
        {
            if (ascii[i] >= 0 && ascii[i] < resultIndex)
                resultIndex = ascii[i];

        }
        if (resultIndex != s.size())
            return s[resultIndex];
        return ' ';
    }
};
/*int main()
{
    string test1 = "leetcode";

    Solution s1;
    cout<<s1.firstUniqChar(test1);

}*/