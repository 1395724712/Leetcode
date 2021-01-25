/**
 * Copyright@wh
 * Author:wh
 * Description:使用栈（先进后出）实现队列（先进先出）的功能
 * Resolution:两个栈，一个输入，一个输出
*/

#include<stack>
using namespace std;

class MyQueue {
public:
    stack<int> stdIn,stdOut;
    /** Initialize your data structure here. */
    MyQueue() {

    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        stdIn.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if(stdOut.empty()){
            while(!stdIn.empty()){
                int elem = stdIn.top();
                stdIn.pop();
                stdOut.push(elem);
            }
        }
        int res = stdOut.top();
        stdOut.pop();
        return res;
    }
    
    /** Get the front element. */
    int peek() {
        int res = pop();
        stdOut.push(res);
        return res;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return stdOut.empty()&&stdIn.empty();
    }
};
