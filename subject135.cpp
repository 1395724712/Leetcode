/*
* Copyright@wh
* Author:wh
* Date:20210302
* Description:根据得分分发糖果
* Resolution:从左到右来一遍，然后从右到左再来一遍
*/

#include<vector>
using namespace std;
class Solution {
public:
    int candy(vector<int>& ratings) {
        int sum = 0;
        vector<int> res(ratings.size(),1);
        //从左到右，根据左值赋给右值
        for(int i = 0;i<ratings.size()-1;i++){
            if(ratings[i+1]>ratings[i]){
                res[i+1] = res[i]+1;
            }
        }

        //从右到左，根据右值赋左值
        sum = res[ratings.size()-1];
        for(int i = res.size()-2;i>=0;i--){
            if(ratings[i]>ratings[i+1]){
                ratings[i] = ratings[i]>ratings[i+1]?ratings[i]:ratings[i+1];
            }
            sum+=ratings[i];
        }

        return sum;
    }
};