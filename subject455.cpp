/**
* Copyright@wh
* Author:wh
* Date:20210225
* Description:分饼干
* Resolution:这个我准备采用从胃口小到胃口大的开始满足
*/

#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        //首先对序列进行排序
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());

        //设置指向饼干的指针
        int index = 0;

        int res = 0;

        //然后开始遍历
        for(auto elem:g){
            if(index>=s.size()){
                break;
            }
            while(index<s.size()){
                if(s[index]>=elem){
                    //能够满足
                    res++;
                    index++;
                    break;
                }
                index++;
            }
        }

        return res;
    }
};