/*
* Copyright@wh
* Author:wh
* Date:20210309
* Description:何时买入并于何时卖出股票，能获得最大利润
* Resolution:动态规划，pro[i] = max{pro[i-1],price[i]-hold[i-1]}
* hold[i] = min{price[i],hold[i-1]}
*/
#include <cstdlib>
#include<vector>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()==0) return 0;

        vector<int> pro;
        vector<int> hold;

        pro.push_back(-1*prices[0]);
        hold.push_back(prices[0]);

        for(int i = 1;i<prices.size();i++){
            int tmp1 = pro[i-1]>(prices[i]-hold[i-1])?pro[i-1]:(prices[i]-hold[i-1]);
            pro.push_back(tmp1);
            int tmp2 = hold[i-1]<prices[i]?hold[i-1]:prices[i];
            hold.push_back(tmp2);
        }
        if(pro.back()<=0) return 0;
        return pro.back();
    }
};