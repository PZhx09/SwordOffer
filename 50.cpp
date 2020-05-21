#include<iostream>
#include<string>
#include<set>
#include<map>
#include<vector>
using namespace std;

class Solution {
public:
    //ʹ�����������ṹset���ˣ�һ�������жϣ�һ����������ֻ����һ�ε�
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
    //��һ�������ṹ����,��Ϊmap��¼��˳������ֻ�ñ���һ��
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
    //����������̫���ѣ�ͳ�ƴ�������
    //��������Ҫ����set��
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
    //ǰ��ķ�����Ҫ���������ַ��������Ҷ�Ҫ�õ�hash
    //��ϸ���룬һ��ֻ��128���ַ�����ôֱ�ӷ���һ��128�����鲻�����ˣ���������-1��ʾû���֣�-2��ʾ���ظ���>0��ʾ���ַ����е�λ�á�
    //���ķ���������������
    //int��char��������ת��
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