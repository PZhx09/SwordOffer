#include<iostream>
#include<vector>
using namespace std;

class Solution {
    //�������ܵ���ĸ���
    //ÿ��4��ѡ����Ȼ���ݷ����������뵽�ݹ�
    //1����������  ���������жϣ����������Ǵ�0,0�����ģ���һ���ܷ񵽴������
    //�ݹ�������
    //����������һ��ȫ�ֱ���count����¼���ߵĸ���
    //��ʵû��Ҫcount=1+�ݹ鷵��   �Ϳ�����(1�ǵ�ǰ���ӣ��ݹ鷵������һ�������ܵ���ĸ�����)   ������Ҫά��·�������ҵķ���Ҳ���
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
        //�ܲ��ܵ������εݹ�ǰ�ж�
        //�Ƿ����ظ�·����Ҳ������ж�ǰ�����ж�
        count++;
        road[locationX][locationY] = 1;

        //����������
        //��
        if (locationX - 1 >= 0 && road[locationX - 1][locationY] != 1 && DigitPositionSum(locationX - 1, locationY) <= k)
            selectroad(road, locationX - 1, locationY, k, count, m, n);
        //��
        if (locationX + 1 < m && road[locationX + 1][locationY] != 1 && DigitPositionSum(locationX + 1, locationY) <= k)
            selectroad(road, locationX + 1, locationY, k, count, m, n);
        //��
        if (locationY -1 >= 0 && road[locationX ][locationY-1] != 1 && DigitPositionSum(locationX , locationY-1) <= k)
            selectroad(road, locationX , locationY - 1, k, count, m, n);
        //��
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