/*
* Copyright@wh
* Author:wh
* Date:20210310
* Description:某一点数出现的概论
* Resolution:dp[n][j] = dp[n-1][j-i]       0<=i<=6
* 空间优化的那个没看明白，先写个基本的吧
*/

#include<vector>
using namespace std;
class Solution {
public:
    vector<double> dicesProbability(int n) {
        vector<vector<int>> dp;

        //初始化n=1的情况
        dp.push_back(vector<int>(6,0));
		for (int i = 0; i < dp[0].size(); i++) dp[0][i] = 1;

        //然后开始根据n，基于公式逐个计算
        for(int k = 1;k<n;k++){
            dp.push_back(vector<int>{});
            for(int j = k;j<(k+1)*6;j++){
                int sum = 0;//计数值
                for(int i = 1;i<=5;i++){
                    if(j-i<=0) break;
                    sum+=dp[k-1][j-i];
                }
                dp[k].push_back(sum);
            }
        }

        int all = pow(6,n);//一共的可能性
        vector<double>res;
        for(int i = n;i<=6*n;i++){
            res.push_back(1.0*dp[n-1][i-1]/(1.0*all));
        }
        return res;
    }
};
