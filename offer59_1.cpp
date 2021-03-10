/*
* Copyright@wh
* Author:wh
* Date:20210310
* Description:滑动窗口的最大值
* Resolution:维持一个从栈底到栈顶的递减序列
*/

#include<vector>
#include<stack>
#include<list>
using namespace std;
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        list<int> sta;
        // sta.push_back(nums[0]);

        for(int i =0;i<k;i++){
            while(!sta.empty()&&nums[i]>sta.back()) sta.pop_back();
            sta.push_back(nums[i]);
        }
        res.push_back(sta.front());

        //然后依次压栈
        for(int i = k;i<nums.size();i++){
            if(nums[i-k]==sta.front()) sta.pop_front();

            while((!sta.empty())&&nums[i]>sta.back()) sta.pop_back();
            sta.push_back(nums[i]);

            res.push_back(sta.front());
        }

        return res;
    }
};