#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    string reverseLeftWords(string s, int n) {
        if (n > s.length())
            return NULL;
        //return s.substr(n, s.length() - n) + s.substr(0, n);
        return (s + s).substr(n, s.length());//��������substr������1��substr�Ϳ��Խ��
    }
};

/*int main()
{
    Solution s1;
    string s = "abcdefg";
    cout << s1.reverseLeftWords(s, 2) << endl;
}*/