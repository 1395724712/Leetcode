/**
 * Copyright@wh
 * Author:wh
 * Date:20210112
 * Description:给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。
 * Resolution:拿数组做哈希表 https://mp.weixin.qq.com/s/vM6OszkM6L1Mx2Ralm9Dig
*/

#include<stdio.h>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        //初始化一个数组做哈希表
        vector<int> hashList(26,0);
        //将s中字符输入哈希表中
        for(auto elem:s){
            hashList[elem-'a']++;
        }
        //之后进行对应t
        for(auto elem:t){
            hashList[elem-'a']--;
        }
        //然后进行检测
        for(auto val:hashList){
            if(val!=0){
                return false;
            }
        }

        return true;
    }
};