#include<iostream>
using namespace std;

#define eps 1e-12
//第一个知识点，C++里double不能用==比较，这是因为计算器误差
//只能相减，小于一个特别小的数别比较
//第二个知识点，e是以10为底，例如1e-9  就是1乘10的-9次方
class Solution {
public:/*
    double myPow(double x, int n) {
        if (x<(eps) && x>(-eps))
            return 0;
        if (n == 0)
            return 1.0;
        if (x > 1.0 - eps && x < 1.0 + eps)
            return 1.0;
        if (x > -1.0 - eps && x < -1.0 + eps)
        {
            return n % 2 == 0 ? 1.0 : -1.0;
        }
        double result = 1.0;
        if (n > 0)
        {
            
            while (n > 0)
            {
                result = result * x;
                n--;
                if (result<(eps) && result>(-eps))
                    return 0;
            }
                
        }
        else
        {
            while (n < 0)
            {
                result = result / x;
                n++;
                if (result<(eps) && result>(-eps))
                    return 0;
            }
        }
        return result;
    }*/


    //快速幂方法    

    double myPow(double x, int n) {
        if (x == 1 || n == 0) return 1;
        double ans = 1;
        long long exponent=n;
        if (n < 0)
        {
            exponent = -exponent;
            x = 1 / x;
        }

        while (exponent)
        {
            if (exponent & 1) ans *= x;
            x *= x;
            exponent = exponent >> 1;
        }

        return ans;
    }

};

/*int main()
{
    double a = 1.0;
    double b = 1.00;
    if (a == b)
        cout << "ok" << endl;
    Solution s1;
    cout << s1.myPow(-2.00000, -2147483648) << endl;
}*/