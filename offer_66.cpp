/**
* Copyright@wh
* Author:wh
* Description:构建乘积数组
* Resulution:将乘积矩阵划分为上三角和下三角，先计算出上三角的值，再计算下三角，然后相称即可
*/

#include<vector>
using namespace std;

class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        

        vector<int> res(a.size(),1);//结果矩阵

        // 先计算上矩阵
        for(int i = a.size()-2;i>=0;i--){
            res[i] = res[i+1]*a[i+1];
        }        

        //然后计算下矩阵
        int tmp = 1;
        for(int i = 1;i<a.size();i++){
            tmp = tmp*a[i-1];
            res[i] = tmp * res[i];
        }

        return res;
    }
};