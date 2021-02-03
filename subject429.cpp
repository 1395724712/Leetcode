/**
 * Copyright@wh
 * Author:wh
 * Date:20210203
 * Description: 多个子节点的层次遍历
 * Reslution: 换汤不换药
*/

#include<vector>
#include<queue>
#include<stdio.h>

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
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        queue<Node*> que;
        if(root){
            que.push(root);
        }

        while(!que.empty()){
            size_t len = que.size();
            vector<int> vec;
            for(int i =0;i<len;i++){
                Node* tempNode = que.front();
                que.pop();
                vec.push_back(tempNode->val);
                for(auto elem:tempNode->children){
                    que.push(elem);
                }
            }
            res.push_back(vec);
        }

        return res;
    }
};