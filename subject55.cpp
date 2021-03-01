/**
* Copyright@wh
* Author:wh
* Date:20210301
* Description:跳跃游戏
* Resolution:贪心，依次遍历数组中的每个元素检查是否能够抵达，如果不能则跳出并返回
*/

#include<vector>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int mostDis = nums[0];
        for(int i = 1;i<nums.size();i++){
            if(i>mostDis) return false;
            mostDis = mostDis>i+nums[i]?mostDis:i+nums[i];
        }
        return true;
    }
};