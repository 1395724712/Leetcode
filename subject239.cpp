/**
 * Copyright@wh
 * Author:wh
 * Date:20210129
 * Description:一个队列，一个滑动窗口，给出滑动窗口中的最大值
 * Resolution:这题有点难，先要定义一个单调队列，然后返回单调队列中的最大值
 * https://mp.weixin.qq.com/s/8c6l2bO74xyMjph09gQtpA
*/
#include<vector>
#include<deque>
using namespace std;

class Solution {
private:
    //首先定义额外的数据类型
    class Mydeque{
    public:
        deque<int> que;
        void push(int x){
            while(!que.empty()&&x>que.back()){
                que.pop_back();
            }
            que.push_back(x);
        }
        void pop(int x){
            if(!que.empty()&&x == que.front()){
                que.pop_front();
            }
        }
        int front(){
            return que.front();
        }    
    };
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        Mydeque que;
        vector<int> res;
        //先输入前k个元素
        for(int i=0;i<k;i++){
            que.push(nums[i]);
        }
        res.push_back(que.front());
        //然后依次遍历
        for(int i = k;i<nums.size();i++){
            que.pop(nums[i-k]);
            que.push(nums[i]);
            res.push_back(que.front());
        }
        return res;
    }
};