/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
//这道题可以不用开辟这么多新的内存，可以用l1和l2中的数据，应该看看解析
        ListNode* tmp1 = l1;
        ListNode* tmp2 = l2;
        ListNode* l3 = new ListNode(-1);
        ListNode* res = l3;
        while(tmp1!=NULL || tmp2!=NULL){
            if(tmp1==NULL){
                l3->next = new ListNode(tmp2->val);
                tmp2 = tmp2->next;
                l3 = l3->next;
                }
            else if(tmp2==NULL){
                l3->next = new ListNode(tmp1->val);
                tmp1 = tmp1->next;
                l3 = l3->next;
                }
            else if(tmp1->val > tmp2->val){
                l3->next = new ListNode(tmp2->val);
                tmp2 = tmp2->next;
                l3 = l3->next;
            }
            else if(tmp1->val <= tmp2->val){
                l3->next = new ListNode(tmp1->val);
                tmp1 = tmp1->next;
                l3 = l3->next;
            }            
        }
        return res->next;
    }
};