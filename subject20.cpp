/**
 * Copyright@wh
 * Author:wh
 * Date:20210127
 * Description:检查括号串是否有效
 * Resolution:这是一个栈的典型应用。左括号压栈，右括号弹栈
 * https://mp.weixin.qq.com/s/nLlmPMsDCIWSqAtr0jbrpQ
*/

#include<string>
#include<stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(auto elem:s){
            if(elem == '('){
                st.push(')');
            }
            else if(elem == '{'){
                st.push('}');
            }
            else if(elem == '['){
                st.push(']');
            }
            else if(st.empty()||st.top()!=elem){
                return false;
            }
            else{
                st.pop();
            }
        }
        return st.empty();
    }
};