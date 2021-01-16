/**
 * Copyright@wh
 * Author:wh
 * Date:20210115
 * Description:给定一个字符串，逐个翻转字符串中的每个单词，并删除多于的空格
 * Resolution:先删除空格，然后整体反转，最后单词单独反转
*/

#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        if(s.size()<2){
            return s;
        }
        //1.双指针删除空格
        int slowIndex = 0;
        int fastIndex = 0;
        //先删除头部空格
        while(s[fastIndex]==' '){
            fastIndex++;
        }
        //删除中间多余空格
        for(;fastIndex<s.size();fastIndex++){
            if(fastIndex-1>0&&s[fastIndex-1]==s[fastIndex]
            &&s[fastIndex]==' '){
                continue;
            }
            else{
                s[slowIndex++] = s[fastIndex];
            }
        }
        //删除尾部空格
        if(slowIndex-1>=0&&s[slowIndex-1]==' '){
            s.resize(slowIndex-1);
        }
        else{
            s.resize(slowIndex);
        }

        //2.然后整体反转，直接掉包吧
        reverse(s.begin(),s.end());

        //3.最后逐个单词反转
        slowIndex = fastIndex = 0;
        while(1){
            //寻找单词边界
            while(fastIndex<s.size()&&s[fastIndex]!=' '){
                fastIndex++;
            }
            fastIndex--;
            //然后反转
            while(slowIndex<fastIndex){
                auto tmp = s[slowIndex];
                s[slowIndex] = s[fastIndex];
                s[fastIndex] = tmp;
                slowIndex++;
                fastIndex--;
            }

            fastIndex = slowIndex;

            //然后移动双指针到单词边界
            while(s[slowIndex]!=' '){
                if(slowIndex==s.size()-1){
                    return s;
                }
                slowIndex++;
                fastIndex++;
            }
            slowIndex++;
            fastIndex++;
        }
        return s;
    }
};