#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    //想法：先把每个单词提取出来，加入到vector中，然后反过来合成一个string
    //时间复杂度O(length)  空间复杂度O(length)
    /*string reverseWords(string s) {
        if (s == "")
            return s;
        vector<string> data;
        int i = 0;
        while (i < s.length())
        {
            while (i< s.length()&&s[i] == ' ')
                i++;
            string tmp;
            while (i < s.length() && s[i] != ' ')
            {
                tmp = tmp + s[i];
                i++;
            }
            if(tmp.length()>0)
                data.push_back(tmp);
        }
        string reverseS;
        if (data.size() == 0)
            return reverseS;
        
        for (int i = data.size() - 1; i > 0; i--)//这里要注意的是 最后一个多加了一个' '
            reverseS = reverseS+data[i]+' ';
        reverseS = reverseS + data[0];
        return reverseS;

    }*/

    //2\书上的标准方法是  反转整个字符串 ，然后反转子串
    //时间按复杂度O(length)，空间复杂度O(length)
    string reverseWords(string s) {
        if (s == "")
            return s;
        reverse(s.begin(), s.end());
        int i = 0;
        int idx = 0;
        while (i < s.length())
        {
            while (i < s.length() && s[i] == ' ')
                i++;//找到第一个非空的单词
            if (i == s.length())//后面全部都是空格了
                break;

            if (idx != 0) s[idx++] = ' ';  //不是第一个单词，前面应该补一个空格
            int start = i;
            while (i < s.length() && s[i] != ' ')
            {
                s[idx++] = s[i++];  //向前搬字母
            }
            reverse(s.begin() + idx-(i-start), s.begin() + idx);

        }
        s.erase(s.begin() + idx, s.end());//idx后面的都是空格了

        return s;

    }

    //3、题解中看到了一个很棒的方法   和自己的很像
    //从后向前读单词，然后加在ans里
    //时间复杂度O(n) 空间复杂度O(1)   
    /*string reverseWords(string s) {
        if (s == "")
            return s;
        string ans;
        int i = s.length()-1;
        while (i >= 0)
        {
            while (i >= 0 && s[i] == ' ')
                i--;
            string tmp;
            int end = i;
            while (i >= 0 && s[i] != ' ')
            {
                i--;
            }
            if(i!=end)
                ans += s.substr(i + 1, end - i) + " ";//这里存在一个问题，就是如果全是空格，他也会执行一次  所以要加一次判断
            
        }
        if (ans.length() > 0) ans.erase(ans.end()-1);
        return ans;

    }*/
};

/*int main()
{
    string s = "  hello world!  ";
    Solution s1;
    cout << "[";
    cout<<s1.reverseWords(s);
    cout << "]";
}*/