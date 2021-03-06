/**
* Copyright@wh
* Author:wh
* Description:将字符串连成整数
* Resolution:不就是逐项检查，直到第一个非数字为止
*/
#include<string>
using namespace std;
class Solution {
public:
    int strToInt(string str) {
        long res = 0;
        //去掉前面的空格
        int beg = 0;
        int sign = 1;
        for(;beg<str.size();beg++){
            if(str[beg]<=122&&str[beg]>=65) return 0;//不符合条件
            if(str[beg]=='-'){
                sign = -1;
                beg++;
                break;
            }  
            if(str[beg]>=48&&str[beg]<=57) break;
        }

        for(;beg<str.size();beg++){
            if(str[beg]>=48&&str[beg]<=57) res = res*10 + str[beg] - 48;
            else break;
        }

        res = res*sign;

        if(res<INT_MIN) return INT_MIN;
        if(res>INT_MAX) return INT_MAX;
        return res;
    }
};