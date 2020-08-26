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

class Solution2 {
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

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* l3 = new ListNode(0);
        ListNode* p = l1;
        ListNode* q = l2;
        if(l1 == NULL && l2 ==NULL) return NULL;
        else if(l1 == NULL && l2 != NULL) return l2;
        else if(l1 != NULL && l2 == NULL) return l1;   //虽然题目已经给出了非空，还是得初步判断
        else{
            ListNode* temp = l3;
            int flag = 0, sum =0, x=0, y=0;
            while(p!=NULL || q!=NULL){
                x = (p!=NULL)? (p->val): 0;
                y = (q!=NULL)? (q->val): 0;
                sum = x + y + flag;
                flag = sum/10;
                temp->next = new ListNode(sum % 10);
                temp = temp->next;
                if(p!=NULL) p=p->next;
                if(q!=NULL) q=q->next;

            }
            if (flag>0) temp->next = new ListNode(flag);
        }
        return l3->next;
        

    }
};



// @lc code=end

