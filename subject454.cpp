/**
 * Copyright@wh
 * Author:wh
 * Date:20210112
 * Description:四数相加2，四个数组寻找和为0的元组数量
 * Resolution:map统计前两个数组的和的数量，然后到第三四个数组中进行匹配
 * Reference:https://mp.weixin.qq.com/s/Ue8pKKU5hw_m-jPgwlHcbA
*/

#include<unordered_map>
#include<vector>
using namespace std;

class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int,int> umap;
        for(auto elemA:A){
            for(auto elemB:B){
                umap[elemA+elemB]++;
            }
        }

        int count = 0;

        for(auto elemC:C){
            for(auto elemD:D){
                if(umap.find(0-(elemC+elemD))!=umap.end()){
                    count += umap[0-(elemC+elemD)];
                }
            }
        }

        return count;

    }
};