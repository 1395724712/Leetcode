/*
 * Copyright@wh
 * Author:wh
 * Date:20210310
 * Description：筛子点数和出现的概率
 * Resolution:dp[j] = dp[j-i] i从1到6
 * 从n-1个骰子的情况推n个骰子的情况
 */
#include<vector>
using namespace std;

class Solution {
public:
	vector<double> dicesProbability(int n) {
		vector<int> dp(n * 6, 0);
		//初始化前6项
		for(int i = 0;i<6;i++)
		{
			dp[i] = 1;
		}

		//然后每增加一个骰子，从后向前初始化
		for(int k = 2;k<=n;k++)
		{//从两个骰子的情况开始
			for(int j = 6*k-1;j>=0;j--)
			{
				dp[j] = 0;
				for(int i =1;i<=6;i++)
				{
					if (j - i < 0) break;
					dp[j] += dp[j-i];
				}
			}
		}

		int all = pow(6, n);
		vector<double> res;
		for(int i = n-1;i<dp.size();i++)
		{
			res.push_back(1.0*dp[i] / all);
		}
		return res;
	}
};