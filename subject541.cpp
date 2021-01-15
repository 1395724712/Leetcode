/**
 * Copyright@wh
 * Author:wh
 * Date:20210112
 * Description:给定一个字符串 s 和一个整数 k，你需要对从字符串开头算起的每隔 2k 个字符的前 k 个字符进行反转。
 * Resolution:还是双指针法
*/

#include<string>
using namespace std;

class Solution {
public:
    string reverseStr(string s, int k) {
        for(int i = 0; i<s.size();i+=2*k){
            int beg = i;
            int end = i+k-1<s.size()?i+k-1:s.size()-1;
            while(beg<end){
                auto tmp = s[beg];
                s[beg] = s[end];
                s[end] = tmp;
                beg++;
                end--;
            }
        }
        return s;
    }
};