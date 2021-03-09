/*
* Copyright@wh
* Author:wh
* Date:20210309
* Description:检查是不是顺子
* Resolution:升序排序，检查有几个gap，有几个0
*/
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    bool isStraight(vector<int>& nums) {
        int countZero = 0;//0的数量
        int countGap = 0;//gap的数量
        bool flag = false;//是否开始检查gap
        sort(nums.begin(),nums.end());

        for(int i = 0;i<nums.size();i++){
            if(nums[i]==0) countZero++;
            if(nums[i]!=0&&flag == false) {
                flag = true;//开始检查gap
                continue;
            }
            if(flag==true&&nums[i]==nums[i-1]) return false;
            if(flag == true) countGap += nums[i] - nums[i-1]-1; 
            
        }
        return countZero>=countGap;
    }
};