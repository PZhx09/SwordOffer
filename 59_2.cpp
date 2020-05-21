#include<iostream>
#include<deque>
#include<queue>
using namespace std;


//�����ʱ���סһ��
//����������˵�����벻���÷����Ϳ��Ų���   Ϲ��һ������Ҳ��AC�ˣ�   ����������˵����
/*class MaxQueue {
public:
    int* data;
    int max;
    int front, end;//frontָ���һ��Ԫ�أ�endָ�����һ��Ԫ�صĺ�һ��λ��
    MaxQueue() {
        data = new int[10000];
        front = 0;
        end = 0;
        max = -1;
    }

    int max_value() {
            return max;
    }

    void push_back(int value) {
        if (front == end)
        {
            max = value;
        }
        data[end++] = value;
        if (value > max)
            max = value;
    }

    int pop_front() {
        if (front == end)
            return -1;
        if (data[front] == max)
        {
            //����Ѱ��max
            if (front + 1 == end)
                max = -1;
            else
            {
                max = data[front + 1];
                for (int i = front + 2; i < end; i++)
                {
                    if (max < data[i])
                        max = data[i];
                }
            }
        }
        return data[front++];
    }
};*/
//ʹ�ø����ṹ ˫�˶��� �����������ֵ
//������������Լ���0ʵ�֣����Կ�����ʵ��һ����max��ջ��Ȼ������ջ�ϳ�һ��
class MaxQueue {
public:
    queue<int> q;
    deque<int> d;
    MaxQueue() {

    }

    int max_value() {
        if (d.empty())
            return -1;
        return d.front();
    }

    void push_back(int value) {
        q.push(value);
        while (!d.empty() && value > d.back())
            d.pop_back();
        d.push_back(value);
    }

    int pop_front() {
        if (q.empty())
            return -1;
        int ans = q.front();
        if (ans == d.front())
            d.pop_front();
        q.pop();
        return ans;
    }
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */