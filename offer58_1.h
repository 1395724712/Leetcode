#pragma once
/*
 * Copyright@wh
 * Author:wh
 * Date:20210311
 * Description:翻转字符串，但是单词的字母顺序保持不变
 * Resolution: 1 如果要去O(1)的空间复杂度，则要先删除前后空格和中间空格
 * 2 然后在原字符串的基础上先整体反转，然后单个单词再反转
 * 3 如果不要求空间复杂度，就直接将单词读入，然后换个顺序输出即可
 */
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
	string reverseWords(string s) {
		if (s.size() < 1) return{};

		// 1 首先将单词依次读入vector中
		string::iterator end = s.end()-1;
		string::iterator beg = end;

		//消除尾部空格
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
				//找到一个单词
				words.push_back(string(beg + 1, end+1));
				//消除中间空格
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

		//2 最后一个单词
		if (beg!=end&&*beg==' ') words.push_back(string(beg+1, end + 1));
		else if(*beg!=' ') words.push_back(string(beg, end + 1));

		//3 输出字符串
		if (words.size() == 0) return {};

		string res = words[0];

		for(int i=1;i<words.size();i++)
		{
			res += " " + words[i];
		}

		return res;
	}
};