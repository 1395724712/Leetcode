/**
 * Copyright@wh
 * Author:wh
 * Date:20210127
 * Description:重复删除两个相邻相同元素，知道没有两个相邻相同元素为止
 * Resolution:栈，相同则弹栈
 * https://leetcode-cn.com/circle/article/wGp7Y9/
*/

#include<string>
#include<stack>
#include<iostream>
using namespace std;

class Solution {
public:
    string removeDuplicates(string S) {
        stack<char> st;
        for(auto elem:S){
            if(st.empty()||st.top()!=elem){
                st.push(elem);
            }
            else
            {
                st.pop();
            }
        }
        string res(st.size(),'0');
        for(int i = 0;i<res.size();i++){
            res[res.size()-1-i] = st.top();
            st.pop();
        }
        return res;
    }
};