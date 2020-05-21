#include<iostream>
#include<vector>
using namespace std;

//直接遍历  肯定超时   聪明反被聪明误，暴力遍历反而正确
//递归，向右向下   也不行
//这题思路就在于找二维数组矩阵的特性   一般都要想到   四个角   中心  这种特殊位置
/*class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        return findWithLocation(matrix, target, 0, 0);
    }
    bool findWithLocation(vector<vector<int>>& matrix, int target, int i, int j)
    {
        if (i >= matrix.size() || j >= matrix[i].size())
            return false;
        if (matrix[i][j] == target)
            return true;
        return (findWithLocation(matrix, target, i + 1, j) || findWithLocation(matrix, target, i, j + 1));
    }
};*/
//参考矩阵性质，右下角的肯定是最大的   思路有i问题，如果选择右下角的点，那么算法十分复杂 而且如果不是nXn矩阵  算法是错误的·1
/*class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        int i = 0;
        while (matrix[i][i] < target)
        {
            i++;
            if (i >= matrix.size() || i >= matrix[i].size())
                break;
        }
        if (i > matrix.size() || i > matrix[i].size())
        {
            //说明数组越界，遍历未遍历的列和行
            if (i == matrix.size() || i == matrix[i].size())
                return false;
            if (i == matrix.size())
            {
                //行到底了
                for()
            }
            if (i == matrix[i].size())
            {
               // 列到底了

            }
        }
        if (matrix[i][i] == target)
            return true;
        if (matrix[i][i] > target)
        {
            //遍历节点所在的列和行

        }
    }
};*/
/*暴力遍历  成功！！！！
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        for (int i = 0; i< matrix.size(); i++)
        {
            for (int j = 0; j < matrix[i].size(); j++)
            {
                if (matrix[i][j] == target)
                    return true;
            }
        }
        return false;
    }
};*/
//寻找矩阵性质
//注意数组越界的问题，同时注意代码if else的写法
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0)
            return false;
        int row = matrix.size() - 1;
        int column = 0;
        int columns = matrix[0].size();
        while (row >= 0 && column < columns)
        {
            if (matrix[row][column] == target)
                return true;
            else if (matrix[row][column] > target)
            {
                row -= 1;
            }
               
            else 
            {
                column += 1;
            }
                
        }
        return false;
    }
};
/*int main()
{
    Solution s;
    vector<vector<int>> matrix = { {-5} };
    s.findNumberIn2DArray(matrix, -10);
}*/
