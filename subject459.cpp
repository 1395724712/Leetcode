/**
 *Copyright@wh
 *Author:wh
 *Date:20210123
 *Description:给定一个非空的字符串，判断它是否可以由它的一个子串重复多次构成。
 *Resolution:根据kmp算法，计算前缀数组，根据前缀数组绝对是否可重复 
*/

#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    //初始化next数组
    void getNext(vector<int>& next,const string& s){
        int j = 0;
        next.push_back(0);
        for(int i = 1;i<s.size();i++){
            //如果两个值不相等
            while(j>0&&s[j]!=s[i]){
                j = next[j-1];
            }
            //如果两个值相等
            if(s[j]==s[i]){
                j++;
            }
            next.push_back(j);
        }
    }
    bool repeatedSubstringPattern(string s) {
        if(s.size()==0){
            return false;
        }
        vector<int> next;
        getNext(next,s);
        if(next[s.size()-1]!=0&&s.size()%(s.size()-next[s.size()-1])==0){
            return true;
        }
        return false;
    }
};