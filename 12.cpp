#include<iostream>
#include<vector>
#include<set>
using namespace std;

//回溯法，就是遇到不行的回到上一步，直到穷举所有可能
//回溯法非常适合递归   注意横纵坐标的意义
//最初使用set记录路径  其实可以用一个bool型二维数组来搞   使用辅助数组代替set，时间明显缩短
/*class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (board.size() == 0 || word.length() == 0)
            return false;
        char firstchar = word[0];
        set<pair<int, int>> road;
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if (board[i][j] == firstchar)
                {
                    if (startselect(board,word,0,i,j,road))
                        return true;
                    else
                        continue;
                }
            }
        }
        return false;
    }
    bool startselect(vector<vector<char>>& board, string word, int order, int locationX,int locationY, set<pair<int, int>>& road)
    {
        //相等在这次递归前判定，不用管了
        //判断路径是否重叠
        if (road.find(make_pair(locationX, locationY)) != road.end())
            return false;
        road.insert(make_pair(locationX, locationY));

        //边界判断，要注意location  order
        if (order == word.length()-1)
            return true;

        //这里进行递归   注意坐标
        if (locationY - 1 >= 0)//向左
        {
            if (board[locationX][locationY - 1] == word[order + 1])
                if (startselect(board, word, order + 1, locationX, locationY - 1, road))
                    return true;
        }
        if (locationY + 1 < board[0].size())//向右
        {
            if (board[locationX][locationY + 1] == word[order + 1])
                if (startselect(board, word, order + 1, locationX, locationY + 1, road))
                    return true;
        }
        if (locationX - 1 >= 0)//向上
        {
            if (board[locationX - 1][locationY ] == word[order + 1])
                if (startselect(board, word, order + 1, locationX - 1, locationY , road))
                    return true;
        }
        if (locationX + 1 < board.size())//向下
        {
            if (board[locationX + 1][locationY ] == word[order + 1])
                if (startselect(board, word, order + 1, locationX + 1, locationY , road))
                    return true;
        }


        road.erase(make_pair(locationX, locationY));
        return false;
    }
};*/


class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (board.size() == 0 || word.length() == 0)
            return false;
        char firstchar = word[0];
        int** road = new int*[board.size()];
        for (int i = 0; i < board.size(); i++)
            road[i] = new int[board[0].size()];

            for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if (board[i][j] == firstchar)
                {
                    if (startselect(board, word, 0, i, j, road))
                        return true;
                    else
                        continue;
                }
            }
        }
        return false;
    }
    bool startselect(vector<vector<char>>& board, string word, int order, int locationX, int locationY, int** road)
    {
        //相等在这次递归前判定，不用管了
        //判断路径是否重叠
        if (road[locationX][locationY]==1)
            return false;
        road[locationX][locationY] = 1;

        //边界判断，要注意location  order
        if (order == word.length() - 1)
            return true;

        //这里进行递归   注意坐标
        if (locationY - 1 >= 0)//向左
        {
            if (board[locationX][locationY - 1] == word[order + 1])
                if (startselect(board, word, order + 1, locationX, locationY - 1, road))
                    return true;
        }
        if (locationY + 1 < board[0].size())//向右
        {
            if (board[locationX][locationY + 1] == word[order + 1])
                if (startselect(board, word, order + 1, locationX, locationY + 1, road))
                    return true;
        }
        if (locationX - 1 >= 0)//向上
        {
            if (board[locationX - 1][locationY] == word[order + 1])
                if (startselect(board, word, order + 1, locationX - 1, locationY, road))
                    return true;
        }
        if (locationX + 1 < board.size())//向下
        {
            if (board[locationX + 1][locationY] == word[order + 1])
                if (startselect(board, word, order + 1, locationX + 1, locationY, road))
                    return true;
        }


        road[locationX][locationY] = 0;
        return false;
    }
};

/*int main()
{
    Solution s1;
    vector<vector<char>> board = { {'a','a'} };
    string word = "aaa";
    cout<<s1.exist(board, word)<<endl;
}*/