#include<iostream>
using namespace std;


class MinStack {
public:
    /** initialize your data structure here. */
    //��һ����Ҫ���ǵĵط������ǣ����pop��ȥ����Сֵ��ô��
    int* data;
    int datatop;
    int datamin;
    int* minArray;
    int mintop;
    MinStack() {
        data = new int[20000];
        minArray = new int[20000];
        datatop = -1;
        mintop = -1;
        datamin = INTMAX_MAX;
    }

    void push(int x) {

        if (datatop==-1 || x <= datamin)//�����ø���ջ�и�����ĵط����������Ǽ�⵽��minС����ջ����ջʱ���ж��ǲ���min��Ȼ���ж��Ƿ񵯳�
        {                               //���ϣ�ÿ��push����ѹ��min(mintop,x)������ջ��ʱ��Ͳ���Ҫ�ж���     
            datamin = x;                //ʵ����Ҳû�б�Ҫά������mintop���Ѹ���ջҲ����һ��ջ��ջ��������Сֵ������
            mintop++;
            minArray[mintop] = x;
        }
        datatop++;
        data[datatop] = x;
    }

    void pop() {
        if (this->top() == datamin)
        {
            mintop--;
            if(mintop==-1)           //��ջҪע�ⲻ�ܷ���δ��ʼ�����ڴ�λ��
                datamin = INTMAX_MAX;
            else
                datamin = minArray[mintop];
            
        }
        datatop--;
    }

    int top() {
        return data[datatop];
    }

    int min() {
        return datamin;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */
/*int main()
{
    MinStack s1;
    s1.push(2147483646);
    s1.push(2147483646);
    s1.push(2147483647);
    s1.top();
    s1.pop();
    s1.min();
    s1.pop();
    s1.min();
    s1.pop();
    s1.push(2147483647);
    s1.top();
    s1.min();
    s1.push(-2147483648);
    s1.top();
    s1.min();
    s1.pop();
    s1.min();
        //"push","top","min","push","top","min","pop","min"]
        // [2147483647], [], [], [-2147483648], [], [], [], []]
}*/