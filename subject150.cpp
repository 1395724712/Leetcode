/**
 * Copyright@wh
 * Author:wh
 * Date:20210127
 * Description:逆波兰表达式
 * Resolution:如果是数字就压栈，不是就计算
 * https://mp.weixin.qq.com/s/hneh2nnLT91rR8ms2fm_kw
*/

#include<string>
#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> resSt;
        for(auto elem:tokens){
            if(elem == "-"||elem == "+"||elem == "*"||elem =="/"){
                int num1 = resSt.top();
                resSt.pop();
                int num2 = resSt.top();
                resSt.pop();
                char op =elem[0];
                switch(op){
                    case '-':
                    resSt.push(num2-num1);
                    break;
                    case '+':
                    resSt.push(num1+num2);
                    break;
                    case '*':
                    resSt.push(num1*num2);
                    break;
                    case '/':
                    resSt.push(num2/num1);
                    break;
                }
            }
            else{
                resSt.push(stoi(elem));
            }
        }
        return resSt.top();
    }
};