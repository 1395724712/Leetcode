/**
* Copyright@wh
* Author:wh
* Date:20210308
* Description: 位运算加法
* Resolution:不会啊，看的攻略
*/

class Solution {
public:
    int add(int a, int b) {
        while(b!=0){
            int carry = (unsigned int)(a&b)<<1;//这是进位
            a = a^b;//抑或运算
            b = carry;
        }
        return a;
    }
};