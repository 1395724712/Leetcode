/**
* Copyright@wh
* Author:wh
* Date:20210303
* Description:柠檬水找零
* Reslution:得维护手中零钱的数量，然后根据顾客支付的钱找零
*/
#include<vector>
using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        vector<int> change(2,0);
        for(auto client:bills){
            if(client==5) change[0]++;
            else if(client == 10){
                change[1]++;
                if(change[0]<=0){
                    //没有足够5元可以支付
                    return false;
                }
                change[0]--;
            }
            else{
                if(change[0]<=0) return false;
                change[0]--;
                if(change[1]>=1){
                    //第一种找零方式：10+5
                    change[1]--;                  
                }
                else{
                    //第二种找零方式：5*3
                    if(change[0]<2) return false;
                    change[0] = change[0]-2;
                }
            }
        }
        return true;
    }
};