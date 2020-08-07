/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution1 {
public:         //自己写的暴力解，不可取
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = new ListNode(-1);
        ListNode *h = head;
        h->next = new ListNode(1);
        h = h->next;
        int flag = 0;
        while(l1!=NULL||l2!=NULL || flag==1){
            if(l1!=NULL&&l2!=NULL){
                if(flag==0) h->val = l1->val + l2->val;
                else h->val = l1->val + l2->val + 1;

                if(h->val>=10){
                    h->val -= 10;
                    flag = 1;
                    h->next = new ListNode(1);
                    h = h->next;
                    l1 = l1->next;
                    l2  = l2->next;
                    continue;
                }
                flag = 0;
            }
            else if(l1!=NULL&&l2==NULL){
                if(flag == 0) h->val = l1->val;
                else h->val = l1->val + 1;
                if(h->val>=10){
                    h->val -= 10;
                    flag = 1;
                    h->next = new ListNode(1);
                    h = h->next;
                    l1 = l1->next;
                    l2  = l2->next;
                    continue;
                }
                flag = 0;

            }
            else if(l1==NULL&&l2!=NULL){
                if(flag == 0) h->val = l2->val;
                else h->val = l2->val + 1;
                if(h->val>=10){
                    h->val -= 10;
                    flag = 1;
                    h->next = new ListNode(1);
                    h = h->next;
                    l1 = l1->next;
                    l2  = l2->next;
                    continue;
                }
                flag = 0;
            }
            else if(l1==NULL&&l2==NULL&&flag) {
                flag = 0;
                h->val = 1;
                }
            else break;
            if (l1->next!=NULL||l2->next!=NULL||flag == 1){
                h->next = new ListNode(1);
                h = h->next;

            }
                l1 = l1->next;
                l2 = l2->next;

        }
        return head->next;
    }
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head=new ListNode(-1);//存放结果的链表
        ListNode* h=head;//移动指针
        int sum=0;//每个位的加和结果
        bool carry=false;//进位标志
        while(l1!=NULL||l2!=NULL)
        {
            sum=0;
            if(l1!=NULL)
            {
                sum+=l1->val;
                l1=l1->next;
            }
            if(l2!=NULL)
            {
                sum+=l2->val;
                l2=l2->next;
            }
            if(carry)
                sum++;
            h->next=new ListNode(sum%10);
            h=h->next;
            carry=sum>=10?true:false;
        }
        if(carry)
        {
            h->next=new ListNode(1);
        }
        return head->next;
    }
};

// @lc code=end

