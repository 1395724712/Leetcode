#pragma once
/*
 * Copyright@wh
 * Author:wh
 * Date:20210311
 * Description:加减乘除，不带括号的表达式
 * Resolution:1 一个栈
 * 2 碰到加减计算出栈中值，再压栈
 * 3 碰到乘除后，计算出结果再压栈，因为没有括号
 * 4 中间有空格，前后也有空格
 */
#include<string>
#include<stack>
using namespace std;

class Solution {
public:
	int calculate(string s) {
		stack<string> sta;//结果栈
		string::iterator fast = s.begin();
		//消除头部空格
		while (*fast == ' ') fast++;//s 是一个有效表达式，不会是一串空格吧
		string::iterator slow= fast;

		int res = 0;
		//开始遍历并压栈
		while(fast!=s.end())
		{
			if(*fast==' ')
			{//空格就继续
				fast++;
				continue;
			}
			if(*fast=='*')
			{
				//栈中数字做乘法

				//被乘数
				int x = stoi(sta.top());
				sta.pop();
				fast++;
				//寻找乘数
				while (*fast == ' ') fast++;
				slow = fast;
				while (fast!=s.end()&&*fast >= 48 && *fast <= 57) fast++;
				//乘数
				int y = stoi(string(slow, fast));
				//结果压栈
				sta.push(to_string(x*y));
			}
			else if(*fast =='/')
			{
				//除法同乘法

				//被除数
				int x = stoi(sta.top());
				sta.pop();
				fast++;
				//寻找除数
				while (*fast == ' ') fast++;
				slow = fast;
				while (fast != s.end() && *fast >= 48 && *fast <= 57) fast++;
				//除数
				int y = stoi(string(slow, fast));
				//结果压栈
				sta.push(to_string(x/y));
			}
			else if(*fast=='+')
			{
				//加减留到外面
				//剩下的运算符都是加号，不必入栈
				//下一个数字直接压栈
				//寻找下一个数字
				fast++;
				//跳过空格
				while (*fast == ' ') fast++;
				slow = fast;
				//寻找下一个数字
				while (fast!=s.end()&&*fast <= 57 && *fast >= 48) fast++;
				//数字直接压栈
				sta.push(string(slow, fast));
			}
			else if(*fast=='-')
			{
				//如果是减法，则压栈的是下一个数字的相反数
				//寻找下一个数字
				fast++;
				//跳过空格
				while (*fast == ' ') fast++;
				slow = fast;
				//寻找下一个数字
				while (fast!=s.end()&&*fast <= 57 && *fast >= 48) fast++;
				//数字直接压栈
				sta.push("-"+string(slow, fast));
			}
			else
			{
				//数字直接压栈
				slow = fast;
				while (*fast <= 57 && *fast >= 48) fast++;
				sta.push(string(slow, fast));
			}
		}

		//然后处理加减
		res = stoi(sta.top());
		sta.pop();
		while(!sta.empty())
		{
			string elem = sta.top();
			sta.pop();
			int y = stoi(elem);
			res += y;
			
		}

		return res;
	}
};