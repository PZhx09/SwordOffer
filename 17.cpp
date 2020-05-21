#include<iostream>
#include<vector>
using namespace std;
//陷阱是大数问题，但是leetcode上没有陷阱
//大数问题可以考虑使用char的数组来进行   但是别忘了，结尾一定是\0
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

