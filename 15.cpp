#include<iostream>
#include<vector>
using namespace std;

/*class Solution {
public:
    //��ñ��ó�������Ϊ����Ч�ʺܵ�
    int hammingWeight(uint32_t n) {
        int num = 0;
        while (n)
        {
            if (n & 1)
                num++;
            n >> 1;
        }
        return num;
    }
};*/
class Solution {
public:
    //��ñ��ó�������Ϊ����Ч�ʺܵ�
    int hammingWeight(uint32_t n) {
        int num = 0;
        while (n)
        {
            n = n & (n - 1);
            num++;
        }
        return num;
    }
};
/*int main()
{
    Solution s1;
    cout<<s1.hammingWeight(9) << endl;
}*/