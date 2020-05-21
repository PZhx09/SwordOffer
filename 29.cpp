#include<iostream>
#include<vector>

using namespace std;

//多画几个图，搞清楚边界问题
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        if (matrix.empty())
            return result;
        if (matrix[0].empty())
            return result;
        int row = matrix.size();
        int column = matrix[0].size();
        
        int borderRight = column-1;
        int borderDown = row-1;
        int borderLeft = 0;
        int borderUp = 1;
        int locationX = 0,locationY = 0;
        while (result.size() != row * column)
        {
            if (locationY <= borderRight)
            {
                while (locationY <= borderRight)
                {
                    result.push_back(matrix[locationX][locationY]);
                    locationY++;
                }
                locationX++;
                locationY--;
                borderRight--;
            }
            else
                break;
            if (locationX <= borderDown)
            {
                while (locationX <= borderDown)
                {
                    result.push_back(matrix[locationX][locationY]);
                    locationX++;
                }
                locationX--;
                locationY--;
                borderDown--;
            }
            else
                break;
            if (locationY >= borderLeft)
            {
                while (locationY >= borderLeft)
                {
                    result.push_back(matrix[locationX][locationY]);
                    locationY--;
                }
                locationX--;
                locationY++;
                borderLeft++;
            }
            else
                break;
            if (locationX >= borderUp)
            {
                while (locationX >= borderUp)
                {
                    result.push_back(matrix[locationX][locationY]);
                    locationX--;
                }
                locationX++;
                locationY++;
                borderUp++;
            }
            else
                break;

        }
        return result;
    }
};
/*int main()
{
    Solution s1;
    vector<int> row1 = { 1,2,3,4 };
    vector<int> row2 = { 5,6,7,8 };
    vector<int> row3 = { 9,10,11,12 };
    vector<vector<int>> matrix = { row1,row2,row3 };
    cout << s1.spiralOrder(matrix).size();
}*/