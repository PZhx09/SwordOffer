#include<iostream>
using namespace std;


class MinStack {
public:
    /** initialize your data structure here. */
    //有一个需要考虑的地方，就是，如果pop出去了最小值怎么办
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

        if (datatop==-1 || x <= datamin)//这里用辅助栈有个巧妙的地方，我这里是检测到比min小，进栈。出栈时，判断是不是min，然后判断是否弹出
        {                               //书上：每次push都会压入min(mintop,x)这样出栈的时候就不需要判断了     
            datamin = x;                //实际上也没有必要维护变量mintop，把辅助栈也看成一个栈，栈顶就是最小值就行了
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
            if(mintop==-1)           //出栈要注意不能访问未初始化的内存位置
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