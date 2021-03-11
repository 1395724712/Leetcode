/*
 * Copyright@wh
 * Author:wh
 * Date:20210310
 * Description��ɸ�ӵ����ͳ��ֵĸ���
 * Resolution:dp[j] = dp[j-i] i��1��6
 * ��n-1�����ӵ������n�����ӵ����
 */
#include<vector>
using namespace std;

class Solution {
public:
	vector<double> dicesProbability(int n) {
		vector<int> dp(n * 6, 0);
		//��ʼ��ǰ6��
		for(int i = 0;i<6;i++)
		{
			dp[i] = 1;
		}

		//Ȼ��ÿ����һ�����ӣ��Ӻ���ǰ��ʼ��
		for(int k = 2;k<=n;k++)
		{//���������ӵ������ʼ
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