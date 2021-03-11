#pragma once
/*
 * Copyright@wh
 * Author:wh
 * Date:20210311
 * Description:��Ϊs����������������
 * Resolution:1 ������������еĿ�ͷΪ (s-(n-1)*n/2)/n ����nΪ���г���
 * 2 �򻯺�Ϊ2*s>n^2-n ��n^2-n-2*s<0
 * 3 ��ö������һԪ���η��̵�������֮���������ʹ�ÿ�ͷΪ������
 */
#include<vector>
#include<math.h>
using namespace std;
class Solution {
public:
	vector<vector<int>> findContinuousSequence(int target) {
		int a = 1;
		int b = -1;
		int c = -2 * target;

		float root1 = (-1 * b + sqrt(pow(b, 2) - 4 * a*c)) / (2 * a);
		float root2 = (-1 * b - sqrt(pow(b, 2) - 4 * a*c)) / (2 * a);

		vector<vector<int>> res;
		
		//Ȼ��ö����һ�µĲ���
		for(int n = root1;n>=root2;n--)
		{
			float beg = (1.0*target - 1.0*(n - 1)*n / 2.0) / (1.0*n);
			//�Ƿ�Ϊ����
			if(beg<target&&beg-int(beg)==0)
			{
				vector<int> tmp;
				for(int i = 0;i<n;i++)
				{
					tmp.push_back(beg + i);
				}
				if (tmp.size() > 1) res.push_back(tmp);
			}
		}

		return res;
		
	}
};