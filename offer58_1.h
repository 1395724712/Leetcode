#pragma once
/*
 * Copyright@wh
 * Author:wh
 * Date:20210311
 * Description:��ת�ַ��������ǵ��ʵ���ĸ˳�򱣳ֲ���
 * Resolution: 1 ���ҪȥO(1)�Ŀռ临�Ӷȣ���Ҫ��ɾ��ǰ��ո���м�ո�
 * 2 Ȼ����ԭ�ַ����Ļ����������巴ת��Ȼ�󵥸������ٷ�ת
 * 3 �����Ҫ��ռ临�Ӷȣ���ֱ�ӽ����ʶ��룬Ȼ�󻻸�˳���������
 */
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
	string reverseWords(string s) {
		if (s.size() < 1) return{};

		// 1 ���Ƚ��������ζ���vector��
		string::iterator end = s.end()-1;
		string::iterator beg = end;

		//����β���ո�
		while(*end==' '&&end!=s.begin())
		{
			end--;
		}

		beg = end;

		vector<string> words;
		
		while(beg!=s.begin())
		{
			if (*beg == ' ')
			{
				//�ҵ�һ������
				words.push_back(string(beg + 1, end+1));
				//�����м�ո�
				while(*beg==' '&&beg!=s.begin())
				{
					beg--;
				}
				end = beg;
			}
			else
			{
				beg--;
			}
		}

		//2 ���һ������
		if (beg!=end&&*beg==' ') words.push_back(string(beg+1, end + 1));
		else if(*beg!=' ') words.push_back(string(beg, end + 1));

		//3 ����ַ���
		if (words.size() == 0) return {};

		string res = words[0];

		for(int i=1;i<words.size();i++)
		{
			res += " " + words[i];
		}

		return res;
	}
};