#include<iostream>
#include<set>
#include<vector>
using namespace std;

class Solution {
public:
    //相当像全排列那个问题
    //将大的问题，分解成小问题来进行解答
    //这里相对于数字全排列T46，又难了一点因为字母可能重复
    //最初是在vector中搜索，来排除重复-->超出时间限制
    //利用set的特性排除重复-->不是很好，时间复杂度很差

    //这里书上的方法也没考虑重复，不过书上的方法很有意思，它是通过不断与“第1个”字符交换来完成的
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
    //移动修改原字符串，要比新建一个字符串，添加删除好多了！！！！
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
            //要先判断重复与否
            if (judge(s, cursor, i))//这里这个judge非常巧妙，仔细想一想，的确这样，只要是换到cursor位置的字符不重复，就行了(因为后面全排列啊，后面乱了没关系)
                continue;
            //与cursor交换，固定cursor的位置，然后再递归
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