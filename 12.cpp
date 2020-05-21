#include<iostream>
#include<vector>
#include<set>
using namespace std;

//���ݷ��������������еĻص���һ����ֱ��������п���
//���ݷ��ǳ��ʺϵݹ�   ע��������������
//���ʹ��set��¼·��  ��ʵ������һ��bool�Ͷ�ά��������   ʹ�ø����������set��ʱ����������
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
        //�������εݹ�ǰ�ж������ù���
        //�ж�·���Ƿ��ص�
        if (road.find(make_pair(locationX, locationY)) != road.end())
            return false;
        road.insert(make_pair(locationX, locationY));

        //�߽��жϣ�Ҫע��location  order
        if (order == word.length()-1)
            return true;

        //������еݹ�   ע������
        if (locationY - 1 >= 0)//����
        {
            if (board[locationX][locationY - 1] == word[order + 1])
                if (startselect(board, word, order + 1, locationX, locationY - 1, road))
                    return true;
        }
        if (locationY + 1 < board[0].size())//����
        {
            if (board[locationX][locationY + 1] == word[order + 1])
                if (startselect(board, word, order + 1, locationX, locationY + 1, road))
                    return true;
        }
        if (locationX - 1 >= 0)//����
        {
            if (board[locationX - 1][locationY ] == word[order + 1])
                if (startselect(board, word, order + 1, locationX - 1, locationY , road))
                    return true;
        }
        if (locationX + 1 < board.size())//����
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
        //�������εݹ�ǰ�ж������ù���
        //�ж�·���Ƿ��ص�
        if (road[locationX][locationY]==1)
            return false;
        road[locationX][locationY] = 1;

        //�߽��жϣ�Ҫע��location  order
        if (order == word.length() - 1)
            return true;

        //������еݹ�   ע������
        if (locationY - 1 >= 0)//����
        {
            if (board[locationX][locationY - 1] == word[order + 1])
                if (startselect(board, word, order + 1, locationX, locationY - 1, road))
                    return true;
        }
        if (locationY + 1 < board[0].size())//����
        {
            if (board[locationX][locationY + 1] == word[order + 1])
                if (startselect(board, word, order + 1, locationX, locationY + 1, road))
                    return true;
        }
        if (locationX - 1 >= 0)//����
        {
            if (board[locationX - 1][locationY] == word[order + 1])
                if (startselect(board, word, order + 1, locationX - 1, locationY, road))
                    return true;
        }
        if (locationX + 1 < board.size())//����
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