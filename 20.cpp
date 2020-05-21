#include<iostream>
#include<string>
using namespace std;

//���ƺܼ򵥣�������Ҫ���ǵ�����ܶ�  Ҫ��һ��ʼ����ù淶���̣���Ȼ����Խ��Խ��
//��ͷ��β����ɨ��������������̫�࣬�Լ�������
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
//��������ָ�ʽ A[.[B]][e|EC]����.B[e|EC]����AC���з���������B���޷�������!!!!
//����˳����ȷ�������Դ�ǰ������������
//�����ʽ�Ƚ����Ҳ���Կ���һ����eΪ�ָ��
//����������С����ָ��ֻ��������

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