/**
* Copyright@wh
* Author:wh
* Date:20210302
* Description:能否一路加油一路旅行
* Resolution: 1 先检查油量累加和能不能大于所需的累加和，如果不能则肯定不行
* 2 从0位置出发，检查能到那个位置，然后从该位置开始下一次循环
* 3 力扣的官方题解给出了，上述合理性的证明
*/

#include<vector>
using namespace std;
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        //1 检查油料累计能不能满足一圈的需求
        //算了这一步没必要，直接开始遍历吧
        

        //从0位置开始遍历
        int beg = 0;
        while(beg<gas.size()){
            int gaSum = 0;
            int coSum = 0;
            int cnt = 0;
            while(cnt<gas.size()){
                int j = (beg+cnt)%gas.size();
                gaSum +=gas[j];
                coSum+=cost[j];
                if(gaSum<coSum){
                    break;
                }
                cnt++;
            }
            if(cnt==gas.size()){
                //转了一圈
                return beg;
            }
            else{
                beg = cnt + beg +1;
            }
        }
        return -1;
    }
};