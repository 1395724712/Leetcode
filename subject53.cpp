/**
* Copyright@wh
* Author:wh
* Date:20210226
* Description:求取最大子序和
* Resolution:动态规划：转移方程为opt[i] = max{opt[i-1]+nums[i],opt[i]}
*/

#include<vector>
using namespace  std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int pre = nums[0];
        int cur;
        int res=pre;

        for(int i =1;i<nums.size();i++){
            cur = pre+nums[i]>nums[i]?pre+nums[i]:nums[i];
            res = res>cur?res:cur;
            pre = cur;
        }

        return res;
    }
};