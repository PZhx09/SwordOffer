#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    //�뷨���Ȱ�ÿ��������ȡ���������뵽vector�У�Ȼ�󷴹����ϳ�һ��string
    //ʱ�临�Ӷ�O(length)  �ռ临�Ӷ�O(length)
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
        
        for (int i = data.size() - 1; i > 0; i--)//����Ҫע����� ���һ�������һ��' '
            reverseS = reverseS+data[i]+' ';
        reverseS = reverseS + data[0];
        return reverseS;

    }*/

    //2\���ϵı�׼������  ��ת�����ַ��� ��Ȼ��ת�Ӵ�
    //ʱ�䰴���Ӷ�O(length)���ռ临�Ӷ�O(length)
    string reverseWords(string s) {
        if (s == "")
            return s;
        reverse(s.begin(), s.end());
        int i = 0;
        int idx = 0;
        while (i < s.length())
        {
            while (i < s.length() && s[i] == ' ')
                i++;//�ҵ���һ���ǿյĵ���
            if (i == s.length())//����ȫ�����ǿո���
                break;

            if (idx != 0) s[idx++] = ' ';  //���ǵ�һ�����ʣ�ǰ��Ӧ�ò�һ���ո�
            int start = i;
            while (i < s.length() && s[i] != ' ')
            {
                s[idx++] = s[i++];  //��ǰ����ĸ
            }
            reverse(s.begin() + idx-(i-start), s.begin() + idx);

        }
        s.erase(s.begin() + idx, s.end());//idx����Ķ��ǿո���

        return s;

    }

    //3������п�����һ���ܰ��ķ���   ���Լ��ĺ���
    //�Ӻ���ǰ�����ʣ�Ȼ�����ans��
    //ʱ�临�Ӷ�O(n) �ռ临�Ӷ�O(1)   
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
                ans += s.substr(i + 1, end - i) + " ";//�������һ�����⣬�������ȫ�ǿո���Ҳ��ִ��һ��  ����Ҫ��һ���ж�
            
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