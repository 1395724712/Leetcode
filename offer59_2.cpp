/**
* Copyright@wh
* Author:wh
* Date:20210305
* Description:队列的最大值
* Resolution:**当一个元素被插入时，已插入的元素中小于该元素的元素对最大值不会再有影响**
*/
#include<queue>
#include<deque>
using namespace std;
class MaxQueue {
private:
    queue<int> que;
    deque<int> deq;
public:
    MaxQueue() {

    }
    
    int max_value() {
        /*
        * deq是一个单调递减
        */
        if(deq.empty()) return -1;
        else return deq.front();
    }
    
    void push_back(int value) {
        /*
        * 根据重要思路：需要保证deq是一个单调递减序列
        */
        que.push(value);
        while(!deq.empty()&&value>deq.back()){
            deq.pop_back();
        }
        deq.push_back(value);
    }
    
    int pop_front() {
        if(que.empty()) return -1;
        int val = que.front();
        que.pop();
        if(val==deq.front()){
            deq.pop_front();
        }
        return val;
    }
};
