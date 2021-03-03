/**
* Copyright@wh
* Author:wh
* Data:20210303
* Description:用最少的箭引爆最多的气球
* Resolution:1 首先按照气球直径的开始从小到大排序
* 2 重叠的气球必然是相邻的气球
* 3 如果相邻的气球没有重叠，则所需箭数就得加1
* 4 如果重叠的话，就得更新最小右边界
*/

#include<vector>
#include<algorithm>
using namespace std;
class Solution {
private:
    static bool cmp(vector<int> f,vector<int> s){
        return f[0]<s[0];
    }
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.size()==0) return 0;
        sort(points.begin(),points.end(),cmp);

        int res = 1;
        for(int i=1;i<points.size();i++){
            if(points[i][0]>points[i-1][1]) res++;
            else points[i][1] = points[i][1]<points[i-1][1]?points[i][1]:points[i-1][1];
        }
        return res;
    }   
};