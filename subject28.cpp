/**
 * Copyright@wh
 * Author:wh
 * Date:20210116
 * Description:给定一个 haystack 字符串和一个 needle 字符串，在 haystack 字符串中找出 needle 字符串出现的第一个位置 (从0开始)。
 * 如果不存在，则返回  -1。
 * Resolution:KMP,先初始化next表，然后根据next表进行匹配
*/

#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    //初始化next数组
    void getNext(vector<int>& next,const string& s){
        int j = 0;
        next.push_back(0);
        for(int i = 1;i<s.size();i++){
            //如果两个值不相等
            while(j>0&&s[j]!=s[i]){
                j = next[j-1];
            }
            //如果两个值相等
            if(s[j]==s[i]){
                j++;
            }
            next.push_back(j);
        }
    }
    int strStr(string haystack, string needle) {

    }
};