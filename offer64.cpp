/*
* Copyright@wh
* Author:wh
* Date:20210309
* Description:不准用乘除，循环，判断，条件语句来进行阶乘操作
* Resolution: 位运算，递归太简单了
* 1 计算式为n*(n+1)/2,n最大为10000即最多有14位1
* 2 乘1为左移一位
* 3 除2为右移一位
* 4 利用&&运算的特性来进行运算
*/

class Solution {
public:
    int sumNums(int n) {
        int A = n;
        int B = n+1;
        int res = 0;

        //1 
        (B&1)&&(res+=A);
        A=A<<1;
        B=B>>1;
        //2 
        (B&1)&&(res+=A);
        A=A<<1;
        B=B>>1;
        //3 
        (B&1)&&(res+=A);
        A=A<<1;
        B=B>>1;
        //4 
        (B&1)&&(res+=A);
        A=A<<1;
        B=B>>1;
        //5 
        (B&1)&&(res+=A);
        A=A<<1;
        B=B>>1;
        //6 
        (B&1)&&(res+=A);
        A=A<<1;
        B=B>>1;
        //7 
        (B&1)&&(res+=A);
        A=A<<1;
        B=B>>1;
        //8 
        (B&1)&&(res+=A);
        A=A<<1;
        B=B>>1;
        //9 
        (B&1)&&(res+=A);
        A=A<<1;
        B=B>>1;
        //10 
        (B&1)&&(res+=A);
        A=A<<1;
        B=B>>1;

        //11 
        (B&1)&&(res+=A);
        A=A<<1;
        B=B>>1;
         
         //12
        (B&1)&&(res+=A);
        A=A<<1;
        B=B>>1;
         
         //13
        (B&1)&&(res+=A);
        A=A<<1;
        B=B>>1;
         
        //14 
        (B&1)&&(res+=A);
        A=A<<1;
        B=B>>1;

        return res>>1;
        
        
    }
};