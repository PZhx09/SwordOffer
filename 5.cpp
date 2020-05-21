#include<iostream>
#include<vector>
#include<string>
using namespace std;

//自己的思路  先遍历得到空格的数目和位置
//然后根据空格的位置进行拼接
//实际上不需要这么麻烦   从前向后遍历，遇到空格+%20  其他不变不就行了
/*class Solution {
public:
    string replaceSpace(string s) {
        vector<int> location;
        int tmp = s.find(' ');
        //先找到空格出现的位置
        while (tmp != -1)
        {
            location.push_back(tmp);
            tmp=s.find(' ', tmp+1);
        }
        if (location.size() == 0)
            return s;

        string replaceResult= s.substr(0, location[0])+"%20";
        for (int i = 1; i < location.size(); i++)
        {
            replaceResult = replaceResult + s.substr(location[i - 1]+1, location[i] - location[i - 1]-1)+"%20";
        }
        replaceResult = replaceResult + s.substr(location.back()+1, s.length() - location.back());
        return replaceResult;
    }
};*/

class Solution {
public:
    string replaceSpace(string s) {
        string replaceResult;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == ' ')
                replaceResult += "%20";
            else
                replaceResult += s[i];
        }
        return replaceResult;
    }
};



/*int main()
{
    string s = "We are happy.      ";
    Solution s1;
    cout << s1.replaceSpace(s)<<endl;
    cout << s<<endl;
}*/

