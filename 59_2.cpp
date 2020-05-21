#include<iostream>
#include<deque>
#include<queue>
using namespace std;


//做题的时候记住一点
//先做出来再说，别想不到好方法就卡着不做   瞎做一气，不也是AC了？   先做出来再说其他
/*class MaxQueue {
public:
    int* data;
    int max;
    int front, end;//front指向第一个元素，end指向最后一个元素的后一个位置
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
            //重新寻找max
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
//使用辅助结构 双端队列 来帮助求最大值
//这题如果是让自己从0实现，可以考虑先实现一个求max的栈，然后两个栈合成一个
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