/**
 * Copyright@wh
 * Author:wh
 * Date:20210111
 * Description:题707，寻找链表中的环
 * Resolution:快慢指针 https://mp.weixin.qq.com/s/_QVP3IkRZWx9zIpQRgajzA
*/

#include<stdio.h>

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int val):val(val),next(NULL){}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* fastPoi = head;
        ListNode* lowPoi = head;

        while(fastPoi!=NULL&&fastPoi->next!=NULL){
            lowPoi = lowPoi->next;
            fastPoi = fastPoi->next->next;

            if(lowPoi == fastPoi){
                ListNode* indexNode1 = head;
                ListNode* indexNode2 = lowPoi;

                while(indexNode1!=indexNode2){
                    indexNode2 = indexNode2->next;
                    indexNode1 = indexNode1->next;
                }
                return indexNode2;
            }
        }

        return NULL;
    }
};