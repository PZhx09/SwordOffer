#include<iostream>
#include<string>
using namespace std;

//看似很简单，但是需要考虑的情况很多  要在一开始就想好规范流程，不然后面越加越乱
//从头到尾无脑扫，这样限制条件太多，自己都混了
/*class Solution {
public:
    bool isNumber(string s) {
        if (s[0] != '.'&&s[0] != '+' && s[0] != '-' && s[0] != ' '&&(s[0] < '0' || s[0]>'9'))
            return false;
        if ((s[0] == '.'||s[0] == '+' || s[0] == '-' || s[0] == ' ') && (s.length() == 1||(s[1] < '0' || s[1]>'9')))
            return false;
        bool point = false;
        if (s[0] == '.')
            point = true;
        bool ise = false;

        for (int i = 1; i < s.length();i++)
        {
            if (s[i] < '0' || s[i]>'9')
            {
                if (i == s.length() - 1&&s[i]!=' '&& s[i] != '.')
                    return false;
                switch (s[i])
                {
                case '.':
                    if (s[i - 1] < '0' || s[i - 1]>'9')
                        return false;
                    if (point || ise)
                        return false;
                    point = true;
                    break;
                case 'e':
                case 'E':
                    if (s[i - 1] < '0' || s[i - 1]>'9')
                        return false;
                    if (point || ise)
                        return false;
                    point = true;
                    break;
                case '-':
                    if (s[i - 1] != 'e' && s[i - 1] != 'E')
                        return false;
                    break;
                case ' ':
                    if (s[i - 1] != ' ' && s[i + 1] != ' ' && (i != s.length() - 1))
                        return false;
                    break;
                default:
                    return false;
                }
            }
        }
        return true;
    }
};*/
//这里的数字格式 A[.[B]][e|EC]或者.B[e|EC]这里AC是有符号整数，B是无符号整数!!!!
//出现顺序是确定的所以从前向后遍历就行了
//这个格式比较巧妙，也可以考虑一下以e为分割点
//底数可以是小数，指数只能是整数

class Solution {
public:
    bool isNumber(string s) {
        int iterator= 0;
        while (s[iterator] == ' ')
            iterator++;
        bool isnum=scanInteger(s, iterator);

        if (s[iterator] == '.')
        {
            iterator++;
            isnum = scanUnsignedInteger(s, iterator)|| isnum  ;
        }
        if (s[iterator] == 'e' || s[iterator] == 'E')
        {
            iterator++;
            isnum= isnum&&scanInteger(s, iterator);
        }
        while (s[iterator] == ' ')
            iterator++;
        return isnum && (iterator == s.length());

    }

    bool scanUnsignedInteger(string s, int& iterator)
    {
        int before = iterator;
        while (s[iterator] >= '0' && s[iterator] <= '9')
            iterator++;
        return iterator > before;
    }

    bool scanInteger(string s, int& iterator)
    {
        if (s[iterator] == '+' || s[iterator] == '-')
            iterator++;
        return scanUnsignedInteger(s, iterator);
    }
};


/*int main()
{
    Solution s1;
    cout<<s1.isNumber("+-5")<<endl;
}*/