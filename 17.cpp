#include<iostream>
#include<vector>
using namespace std;
//�����Ǵ������⣬����leetcode��û������
//����������Կ���ʹ��char������������   ���Ǳ����ˣ���βһ����\0
class Solution {
public:
    vector<int> printNumbers(int n) {
        vector<int> result;
        for (int i = 1; i < pow(10, n);i++)
            result.push_back(i);
        return result;
    }
};

/*int main()
{
    double a = 4;
    double b = 0.1;
    double c=a - b ;
    double d = 3.1 + 0.8;
    if (c == d)
        cout << "ok" << endl;
}*/

