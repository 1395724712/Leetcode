/*
*Copyright@wh
*Author:wh
*Date:20210109
*Description:给定一个正整数 n，生成一个包含 1 到 n2 所有元素，且元素按顺时针顺序螺旋排列的正方形矩阵。
*Resolution:看题解都差点没看懂，https://mp.weixin.qq.com/s/KTPhaeqxbMK9CxHUUgFDmg
*/

#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n,vector<int>(n,0));
        int xStart = 0,yStart = 0;//每一层的起始位置
        int loop = n/2;//外围的层数
        int mid = n/2;//核心
        int count = 1;//数据
        int offset = 1;
        int i = 0, j =0;
        while(loop--){
            j = xStart;
            i = yStart;
            //顶上一层
            for(;j<xStart + n - offset;j++){
                res[i][j] = count++;
            }
            //右边一层
            for(;i<yStart + n - offset;i++){
                res[i][j] = count++;
            }
            //下面一层
            for(;j>xStart;j--){
                res[i][j] = count++;
            }
            //左边一层
            for(;i>yStart;i--){
                res[i][j] = count++;
            }

            xStart++;
            yStart++;

            offset += 2;

        }

        //如果n为奇数，注意填充矩阵核心
        if(n%2){
            res[n/2][n/2] = count++;
        }

        return res;
    }
};