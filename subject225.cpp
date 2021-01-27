/**
 * Copyright@wh
 * Author:wh
 * Date:20210126
 * Description:使用队列（先进先出）实现栈（先进后出）
 * Resolution:两个队列，一个承担备份工作
*/

#include<queue>
using namespace std;

class MyStack {
public:
    queue<int> que1,que2;
    /** Initialize your data structure here. */
    MyStack() {

    }
    
    /** Push element x onto stack. */
    void push(int x) {
        que1.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int elem;
        while(1){
            elem = que1.front();
            que1.pop();
            if(que1.empty()){
                break;
            }
            que2.push(elem);
        }
        que1 = que2;
        while(!que2.empty()){
            que2.pop();
        }
        return elem;
    }
    
    /** Get the top element. */
    int top() {
        return que1.back();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return que1.empty();
    }
};
