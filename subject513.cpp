/**
 * Copyright@wh
 * Author:wh
 * Date:20210207
 * Description:最后一行最左边的元素
 * Resolution:层次遍历，迭代法；逻辑非常简单
 * https://mp.weixin.qq.com/s/MH2gbLvzQ91jHPKqiub0Nw
*/

#include<queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> que;
        que.push(root);
        int res;
        //迭代法层次遍历
        while(!que.empty()){
            int len = que.size();
            for(int i =0 ;i<len;i++){
                TreeNode *tempNode = que.front();
                que.pop();
                if(i==0){
                    //最左边是队列中的第一个
                    res = tempNode->val;
                }
                if(tempNode->left){
                    que.push(tempNode->left);
                }
                if(tempNode->right){
                    que.push(tempNode->right);
                }
            }
        }

        return res;
    }
};