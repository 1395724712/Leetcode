/**
* Copyright@wh
* Author:wh
* Date:20210226
* Description：摆动序列
* Resolution:记录前一个差值是正还是负，然后与当前差值比较
*/

#include<vector>
using namespace std;

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size()<=1) return nums.size();

        int res = 1;

        int preDiff = 0;
        int curDiff = 0;

        for(int i = 1;i<nums.size();i++){
            curDiff = nums[i] - nums[i-1];
            
            if((curDiff<0&&preDiff>=0)||(curDiff>0&&preDiff<=0)){
                res++;
                preDiff = curDiff;
            }
        }

        return res;
    }
};