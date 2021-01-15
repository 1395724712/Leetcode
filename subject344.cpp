/**
 * Copyright@wh
 * Author:wh
 * Date:20210112
 * Description:反转字符串
 * Resolution:双指针  https://mp.weixin.qq.com/s/X02S61WCYiCEhaik6VUpFA
*/

#include<vector>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        for (int i = 0; i < s.size()/2; i++){
            /* code */
            char tmp = s[i];
            s[i] = s[s.size()-1-i];
            s[s.size()-1-i] = tmp;
        }              
    }
};