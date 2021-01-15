/**
 * Copyright@wh
 * Author:wh
 * Date:20210115
 * Description:请实现一个函数，把字符串 s 中的每个空格替换成"%20"。
 * Resolution:先resize扩充，再从后向前使用双指针。https://mp.weixin.qq.com/s/t0A9C44zgM-RysAQV3GZp
*/

#include<string>
using namespace std;

class Solution {
public:
    string replaceSpace(string s) {
        //1.统计空格个数
        int count = 0;
        for(auto elem:s){
            if(elem == ' '){
                count++;
            }
        }
        int i = s.size() - 1;
        //2.重新扩展s的大小
        s.resize(s.size() + count*2);
        int j = s.size() - 1;

        //3.然后从后往前遍历并替换
        while(i<j){
            if(s[i]!=' '){
                s[j] = s[i];
            }
            else{
                s[j] = '0';
                s[--j] = '2';
                s[--j] = '%';
            }
            i--;
            j--;
        }

        return s;
    }
};