/**
* Copyright@wh
* Author:wh
* Date:20210303
* Description:最大不重叠区间
* Resolution:1 根据右区间升序排序，因为右区间小的一定可以取代右区间大的
* 2 求最大不重叠区间的数量
* 3 区间总数减去最大不重叠区间的数量即为结果
*/

#include<vector>
#include<algorithm>
using namespace std;

class Solution {
private:
    static bool cmp(vector<int> f,vector<int> s){
        return f[1]<s[1];
    }
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.size()<=1) return 0;
        sort(intervals.begin(),intervals.end(),cmp);

        int max = 1;
        for(int i =1;i<intervals.size();i++){
            if(intervals[i][0]>=intervals[i-1][1]) max++;
            else{
                //如果不相交也得更新右边界
                intervals[i][1] = intervals[i-1][1];
            }
        }
        return intervals.size() - max;
    }
};