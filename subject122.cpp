/**
*Copyright@wh
*Author:wh
*Date:20210226
*Description:买卖股票
*Resolution:动态规划；每天有两种状态，持有或者出售
*如果出售，有两种可能：前一天持有，然后今天卖出；前一天就卖出即dp[i][0]=max{dp[i-1][0],dp[i-1][1]+price[i]}
*如果持有，有两种可能：前一天买入的；前一天出售，今天买入即dp[i][1] = max{dp[i-1][1],dp[i-1][0]-price[i]}
*/

#include<vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<pair<int,int>> dp;

        //初始化
        dp.push_back({0,-prices[0]});

        for(int i = 1;i<prices.size();i++){
            // dp.push_back({0,0});
            int sell = dp.back().first>dp.back().second+prices[i]?dp.back().first:dp.back().second+prices[i];
            int hold = dp.back().second>dp.back().first-prices[i]?dp.back().second:dp.back().first-prices[i];
            dp.push_back({sell,hold});
        }


        return dp.back().first; 
    }
};