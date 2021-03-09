/*
* Copyright@wh
* Author:wh
* Date:20210309
* Descritpion:转一圈剩下那个
* Resolution:n个圈和n-1剩下的是同一个数字，使用递归来找
*/

class Solution {
public:
    int lastRemaining(int n, int m) {
        //1 递归终止条件
        if(n==1) return 0;
        int x = lastRemaining(n-1,m);
        return (x+m)%n;
    }
};