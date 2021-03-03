/**
* Copyright@wh
* Author:wh
* Date:20210303
* Description:身高，按照要求排序
* Resolution: 先按身高从高到矮排序，然后根据第二个值获得插入位置
*/

#include<vector>
#include<list>
#include<algorithm>
using namespace std;
class Solution {
private:
    static bool cmp(vector<int> a,vector<int> b){
        if(a[0]==b[0]) return a[0]<b[0];
        return a[0]>b[0];
    }
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(),people.end(),cmp);
        vector<vector<int>> que;
        for(auto elem:people){
            que.insert(que.begin()+elem[1],elem);
        }
        return que;
    }
};