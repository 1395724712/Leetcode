/**
* Copyright@wh
* Autorh:wh
* Date:20210301
* Description:跳跃游戏2
* Resolution:记录每一次跳跃的边界border,新的最大所能达到位置，如果新的最大可能达到位置大于数组最大下标的话，即得到结果
*/

#include<vector>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int step = 0;
        int most = nums[0];
        int border = nums[0];
        
        if(nums.size()<=1) return step;
        if(most>=nums.size()-1) return step+1;

        for(int i = 1;i<nums.size();i++){
            //尝试更新最大能达到范围
            most = most>i+nums[i]?most:i+nums[i];

            if(i==border){
                //更新边界
                border = most;
                step++;
                if(border>=nums.size()-1){
                    return step++;
                }
            }
        }
        return -1;
    }
};