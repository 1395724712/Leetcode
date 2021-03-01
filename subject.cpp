/**
* Copyright@wh
* Author: wh
* Date:20210301
* Description:K次取反后的最大化数组和
* Resolution:先排序，然后每次选择最小的那个取反
*/

#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int largestSumAfterKNegations(vector<int>& A, int K) {
        sort(A.begin(),A.end());

        for(int i=0;i<K;i++){
            if(A[i]>=0){
                //如果数组中没有负数，将最小正数数字反复取反即可
                sort(A.begin(),A.end());
                if((K-i)%2==0) break;
                else A[0] = -A[0];
                break;
            }
            A[i] = -A[i];
        }

        int res=0;

        for(int i =0;i<A.size();i++){
            res += A[i];
        }
        return res;
    }
};