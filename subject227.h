#pragma once
/*
 * Copyright@wh
 * Author:wh
 * Date:20210311
 * Description:�Ӽ��˳����������ŵı��ʽ
 * Resolution:1 һ��ջ
 * 2 �����Ӽ������ջ��ֵ����ѹջ
 * 3 �����˳��󣬼���������ѹջ����Ϊû������
 * 4 �м��пո�ǰ��Ҳ�пո�
 */
#include<string>
#include<stack>
using namespace std;

class Solution {
public:
	int calculate(string s) {
		stack<string> sta;//���ջ
		string::iterator fast = s.begin();
		//����ͷ���ո�
		while (*fast == ' ') fast++;//s ��һ����Ч���ʽ��������һ���ո��
		string::iterator slow= fast;

		int res = 0;
		//��ʼ������ѹջ
		while(fast!=s.end())
		{
			if(*fast==' ')
			{//�ո�ͼ���
				fast++;
				continue;
			}
			if(*fast=='*')
			{
				//ջ���������˷�

				//������
				int x = stoi(sta.top());
				sta.pop();
				fast++;
				//Ѱ�ҳ���
				while (*fast == ' ') fast++;
				slow = fast;
				while (fast!=s.end()&&*fast >= 48 && *fast <= 57) fast++;
				//����
				int y = stoi(string(slow, fast));
				//���ѹջ
				sta.push(to_string(x*y));
			}
			else if(*fast =='/')
			{
				//����ͬ�˷�

				//������
				int x = stoi(sta.top());
				sta.pop();
				fast++;
				//Ѱ�ҳ���
				while (*fast == ' ') fast++;
				slow = fast;
				while (fast != s.end() && *fast >= 48 && *fast <= 57) fast++;
				//����
				int y = stoi(string(slow, fast));
				//���ѹջ
				sta.push(to_string(x/y));
			}
			else if(*fast=='+')
			{
				//�Ӽ���������
				//ʣ�µ���������ǼӺţ�������ջ
				//��һ������ֱ��ѹջ
				//Ѱ����һ������
				fast++;
				//�����ո�
				while (*fast == ' ') fast++;
				slow = fast;
				//Ѱ����һ������
				while (fast!=s.end()&&*fast <= 57 && *fast >= 48) fast++;
				//����ֱ��ѹջ
				sta.push(string(slow, fast));
			}
			else if(*fast=='-')
			{
				//����Ǽ�������ѹջ������һ�����ֵ��෴��
				//Ѱ����һ������
				fast++;
				//�����ո�
				while (*fast == ' ') fast++;
				slow = fast;
				//Ѱ����һ������
				while (fast!=s.end()&&*fast <= 57 && *fast >= 48) fast++;
				//����ֱ��ѹջ
				sta.push("-"+string(slow, fast));
			}
			else
			{
				//����ֱ��ѹջ
				slow = fast;
				while (*fast <= 57 && *fast >= 48) fast++;
				sta.push(string(slow, fast));
			}
		}

		//Ȼ����Ӽ�
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