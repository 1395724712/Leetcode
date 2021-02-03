/**
 * Copyright@wh
 * Author:wh
 * Date:20210201
 * Description:在O(nlogn)的时间复杂度内寻找数组的出现频率位列前n的数字
 * Resolution:用一个优先级队列来解决，这个优先级队列是一个小顶堆，这个堆，是一个封装好的完全二叉树
 * https://mp.weixin.qq.com/s/8hMwxoE_BQRbzCc7CA8rng
*/

#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;

class Solution {
public:
    //首先准备谓词
    //将大顶堆变成小顶堆
    class myComparision{
        public:
        bool operator()(const pair<int,int>& lhs,const pair<int,int>& rhs){
            return lhs.second>rhs.second;
        }
        };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>  myMap;
        for(auto elem:nums){
            myMap[elem]++;
        }    
        //然后创建小顶堆
        priority_queue<pair<int,int>,vector<pair<int,int>>,myComparision> myQue;
        for(auto elem:myMap){
            myQue.push(elem);
            if(myQue.size()>k){
                myQue.pop();
            }
        }
        // for (unordered_map<int, int>::iterator it = myMap.begin(); it != myMap.end(); it++) {
        //    myQue.push(*it);
        //    if (myQue.size() > k) { // 如果堆的大小大于了K，则队列弹出，保证堆的大小一直为k
        //         myQue.pop();
        //     }
        // }
        //然后记录结果
        vector<int> res(k);
        for(int i = k-1;i>=0;i--){
            res[i] = myQue.top().first;
            myQue.pop();
        }
        return res;
    }
};
