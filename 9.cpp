#include<iostream>
#include<stack>
using namespace std;

class CQueue {
public:
    stack<int> s1;
    stack<int> s2;
    CQueue() {

    }

    void appendTail(int value) {
        s1.push(value);
    }

    int deleteHead() {
        int result;
        if (!s2.empty())
        {
            result = s2.top();
            s2.pop();
            return result;
        }
        if (s1.empty())
            return -1;
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        result = s2.top();
        s2.pop();
        return result;


    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */