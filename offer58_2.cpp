/**
 * Copyright@wh
 * Author:wh
 * Date:20120116
 * Description:左转字符串
 * Resolution:不使用额外数组空间的方法，先倒转前k个符号，然后倒转从k到字符尾的符号，最后整体倒转
 * https://mp.weixin.qq.com/s/PmcdiWSmmccHAONzU0ScgQ
*/

#include<string>
using namespace std;

class Solution {
public:
    string reverseLeftWords(string s, int n) {
        //先倒转前n个符号
        int i=0,j=n-1;
        while(i<j){
            auto tmp = s[i];
            s[i] = s[j];
            s[j] = tmp;
            i++;
            j--;
        }
        //然后倒转从n到字符尾的元素
        i = n;
        j = s.size() - 1;
        while(i<j){
            auto tmp = s[i];
            s[i] = s[j];
            s[j] = tmp;
            i++;
            j--;
        }
        //最后整体倒转
        i = 0;
        j = s.size() - 1;
        while(i<j){
            auto tmp = s[i];
            s[i] = s[j];
            s[j] = tmp;
            i++;
            j--;
        }

        return s;
    }
};