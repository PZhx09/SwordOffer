#include<iostream>
#include<vector>
using namespace std;

class Solution {
    //机器人能到达的格子
    //每步4个选择，显然回溯法，很容易想到递归
    //1、暴力遍历  利用性质判断，但是这里是从0,0出发的，有一个能否到达的问题
    //递归正常做
    //这里我用了一个全局变量count来记录能走的格子
    //其实没必要count=1+递归返回   就可以了(1是当前格子，递归返回是下一个格子能到达的格子数)   不过都要维护路径，和我的方法也差不多
public:
    int movingCount(int m, int n, int k) {
        int** road = new int* [m];
        int count = 0;
        for (int i = 0; i < m; i++)
            road[i] = new int[n];
        selectroad(road, 0, 0, k,count, m, n);
        return count;
    }
    void selectroad(int** road, int locationX, int locationY, int k, int& count, int m, int n)
    {
        //能不能到达，在这次递归前判断
        //是否有重复路径，也在这次判断前进行判断
        count++;
        road[locationX][locationY] = 1;

        //上下左右走
        //上
        if (locationX - 1 >= 0 && road[locationX - 1][locationY] != 1 && DigitPositionSum(locationX - 1, locationY) <= k)
            selectroad(road, locationX - 1, locationY, k, count, m, n);
        //下
        if (locationX + 1 < m && road[locationX + 1][locationY] != 1 && DigitPositionSum(locationX + 1, locationY) <= k)
            selectroad(road, locationX + 1, locationY, k, count, m, n);
        //左
        if (locationY -1 >= 0 && road[locationX ][locationY-1] != 1 && DigitPositionSum(locationX , locationY-1) <= k)
            selectroad(road, locationX , locationY - 1, k, count, m, n);
        //右
        if (locationY + 1 <n && road[locationX][locationY + 1] != 1 && DigitPositionSum(locationX, locationY + 1) <= k)
            selectroad(road, locationX , locationY+1, k, count, m, n);
        
    }
    int DigitPositionSum(int locationX, int locationY)
    {
        int sumX = 0, sumY = 0;
        sumX = locationX==100?1:locationX / 10 + locationX % 10;
        sumY = locationY==100?1:locationY / 10 + locationY % 10;
        return sumX + sumY;
    }

};

/*int main()
{
    Solution s1;
    cout << s1.movingCount(1, 2, 1)<<endl;
}*/