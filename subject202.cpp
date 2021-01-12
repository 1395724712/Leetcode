/**
 * Copyright@wh
 * Author:wh
 * Date:20210112
 * Description：编写一个算法来判断一个数 n 是不是快乐数。
 * Resolution:思想是如果存在无限循环，则存在某一个求值反复出现 https://mp.weixin.qq.com/s/G4Q2Zfpfe706gLK7HpZHpA
*/

#include<unordered_set>
using namespace std;

class Solution {
public:

    //一个用于求和的函数
    int calSum(int n){
        int sum = 0;
        while(n!=0){
            sum+=(n%10)*(n%10);
            n=n/10;
        }
        return sum;
    }

    bool isHappy(int n) {
        unordered_set<int> set;
        //不断循环，直到和为1或陷入死循环
        while(1){
            int sum = calSum(n);
            if(sum==1){
                return true;
            }
            else if(set.find(sum)!=set.end()){
                return false;
            }
            else{
                set.insert(sum);
            }
            n = sum;
        }
    }
};