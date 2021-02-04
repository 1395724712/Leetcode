/**
 * Copyright@wh
 * Author:wh
 * Date:20210204
 * Description:N叉树的最大深度
 * Resolution:还是照着递归写吧，因为递归还不是很熟，再练练
 * https://leetcode-cn.com/problems/maximum-depth-of-n-ary-tree/
*/

#include<vector>

using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    int maxDepth(Node* root) {
        if(!root){
            return 0;
        }

        int depth = 0;
        for(auto elem:root->children){
            int temp = maxDepth(elem);
            depth = depth>temp?depth:temp;
        }
        return depth+1;
    }
};