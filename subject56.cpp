/**
* Copyright@wh
* Author:wh
* Date:20210304
* Description:合并区间
* Resolution:和763实际上是同一类题目
* 1 先将区间按照开始位置升序排序
* 2 如果后一个的开始位置大于当前已区间的结束位置，则要重新创建区间
* 3 否则将当前区间合并到已合并区间，即修改已合并区间的结束位置
*/

#include<vector>
#include<algorithm>
using namespace std;
class Solution {
private:
    static bool cmp(const vector<int>& a,const vector<int>& b){
        return a[0]<b[0];
    }
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        //1 按照升序排序
        sort(intervals.begin(),intervals.end());
        
        //2 当前区间的开始位置如果大于已合并区间的结束位置，则创建新区间
        //否则合并到已有区间
        int beg=intervals[0][0];
        int end = intervals[0][1];
        vector<vector<int>> res;
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]>end){
                res.push_back({beg,end});
                beg = intervals[i][0];
                end = intervals[i][1];
            }
            else end = end>intervals[i][1]?end:intervals[i][1];
        }
        res.push_back({beg,end});
        return res;
    }
};