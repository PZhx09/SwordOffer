#include<iostream>
#include<vector>
using namespace std;

//ֱ�ӱ���  �϶���ʱ   �������������󣬱�������������ȷ
//�ݹ飬��������   Ҳ����
//����˼·�������Ҷ�ά������������   һ�㶼Ҫ�뵽   �ĸ���   ����  ��������λ��
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
//�ο��������ʣ����½ǵĿ϶�������   ˼·��i���⣬���ѡ�����½ǵĵ㣬��ô�㷨ʮ�ָ��� �����������nXn����  �㷨�Ǵ���ġ�1
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
            //˵������Խ�磬����δ�������к���
            if (i == matrix.size() || i == matrix[i].size())
                return false;
            if (i == matrix.size())
            {
                //�е�����
                for()
            }
            if (i == matrix[i].size())
            {
               // �е�����

            }
        }
        if (matrix[i][i] == target)
            return true;
        if (matrix[i][i] > target)
        {
            //�����ڵ����ڵ��к���

        }
    }
};*/
/*��������  �ɹ���������
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
//Ѱ�Ҿ�������
//ע������Խ������⣬ͬʱע�����if else��д��
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
