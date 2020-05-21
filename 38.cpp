#include<iostream>
#include<set>
#include<vector>
using namespace std;

class Solution {
public:
    //�൱��ȫ�����Ǹ�����
    //��������⣬�ֽ��С���������н��
    //�������������ȫ����T46��������һ����Ϊ��ĸ�����ظ�
    //�������vector�����������ų��ظ�-->����ʱ������
    //����set�������ų��ظ�-->���Ǻܺã�ʱ�临�ӶȺܲ�

    //�������ϵķ���Ҳû�����ظ����������ϵķ���������˼������ͨ�������롰��1�����ַ���������ɵ�
    /*vector<string> permutation(string s) {
        vector<string> result;
        if (s.length() == 0)
            return result;
        string combine;
        set<string> group;
        permutation(group, combine, s);
        for (set<string>::iterator it = group.begin(); it != group.end(); it++)
            result.push_back(*it);
        return result;
    }

    void permutation(set<string>& result, string &combine,string &s)
    {
        if (s.length() == 1)
        {
            combine += s;
            bool exist = false;
            result.insert(combine);
            combine.erase(combine.end()-1);
            return;
        }
        for (int i = 0; i < s.length(); i++)
        {
            combine += s[i];
            s.erase(i, 1);
            permutation(result, combine, s);
            s.insert(s.begin()+i, combine.back());
            combine.erase(combine.end()-1);
        }
    }*/
    //�ƶ��޸�ԭ�ַ�����Ҫ���½�һ���ַ��������ɾ���ö��ˣ�������
    vector<string> permutation(string s) {
        vector<string> result;
        if (s.length() == 0)
            return result;
        int cursor = 0;
        permutation(result, s, cursor);
        return result;
    }
    void permutation(vector<string>& result, string s, int cursor)
    {
        if (cursor == s.length() - 1)
            result.push_back(s);
        for (int i = cursor; i < s.length(); i++)
        {
            //Ҫ���ж��ظ����
            if (judge(s, cursor, i))//�������judge�ǳ������ϸ��һ�룬��ȷ������ֻҪ�ǻ���cursorλ�õ��ַ����ظ���������(��Ϊ����ȫ���а�����������û��ϵ)
                continue;
            //��cursor�������̶�cursor��λ�ã�Ȼ���ٵݹ�
            char tmp = s[cursor];
            s[cursor] = s[i];
            s[i] = tmp;
            permutation(result, s, cursor + 1);
            s[i] = s[cursor];
            s[cursor] = tmp;
        }
    }
    bool judge(string s, int start, int end)
    {
        for (int i = start; i < end; i++)
        {
            if (s[i] == s[end])
                return true;
        }
        return false;
    }
     
};

/*int main()
{
    Solution s1;
    string test1 = "";
    string test2 = "a";
    string test3 = "vpvptjzh";
    vector<string> v1=s1.permutation(test1);
    vector<string> v2 = s1.permutation(test2);
    vector<string> v3 = s1.permutation(test3);
    cout << v1.size() << endl;
    cout << v2[0] << endl;
    cout << v3[0] << endl;
    cout << v3[1] << endl;
    cout << v3[2] << endl;
    cout << v3[3] << endl;
    cout << v3[4] << endl;
    cout << v3[5] << endl;
}*/