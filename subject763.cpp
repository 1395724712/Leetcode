/*
* Copyright@wh
* Author:wh
* Date:20210304
* Description: 划分字母区间
* Resolution：最大重叠区间
* 1 记录每个字母出现的区间
* 2 然后根据开始位置升序排序
* 3 如果前一个开始位置小于下一个的结束位置，则不重叠，当前位置即为分割位置
*/
#include<map>
#include<vector>
#include<string>
#include<algorithm>
#include<iostream>
using namespace std;
class Solution {
private:
    static bool cmp(const pair<int,int>& a,const pair<int,int>& b){
        return a.first<b.first;
    }
public:
    vector<int> partitionLabels(string S) {
        map<char,pair<int,int>> findBE;
        //1 记录每个数字的开始和结束区间
        for(int i =0;i<S.size();i++){
            if(findBE.count(S[i])==0) findBE[S[i]].second = findBE[S[i]].first = i;
            else findBE[S[i]].second = i;
        }

        //2 根据开始位置升序排序
        vector<pair<int,int>> sec;
        for(auto elem:findBE){
            sec.push_back(elem.second);
            // cout<<elem.first<<"\t"<<elem.second.first<<"\t"<<elem.second.second<<endl;
        }
        sort(sec.begin(),sec.end());

        //3 如果前一个的结束位置小于当前的开始位置则要划分区段
        int beg = 0;
        int end = sec[0].second;
        vector<int> res;
        for(int i = 1;i<sec.size();i++){
            if(sec[i].first>end){
                res.push_back(end-beg+1);
                beg = sec[i].first;
                end = sec[i].second;
            }
            else end = end>sec[i].second?end:sec[i].second;
        }
        res.push_back(end-beg+1);
        return res;
    }
};