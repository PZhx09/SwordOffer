#include<iostream>
#include<vector>
using namespace std;
//ͬһ�����⣬���Ƿ�Χ�����
//�������ʹ�ö�̬�滮���������ϣ�Ӧ��Ҳ�ǿ��Եģ�����Ҫ���Ǻܶ�����-->intԽ�硢ȡģ  ȡģ�ĸ���   �ܸ���
//ʹ��̰���㷨����
//qumo
class Solution {
public:
    int cuttingRope(int n) {
        if (n <= 2)
            return 1;
        if (n == 3)
            return 2;
        long result = 1;
        while (n >= 5)
        {
            result = result * 3 % 1000000007;
            n = n - 3;
        }
         result = result* n % 1000000007;
        return result;
    }
};

/*int main()
{
    Solution s1;
    cout<<s1.cuttingRope(120)<<endl;
}*/