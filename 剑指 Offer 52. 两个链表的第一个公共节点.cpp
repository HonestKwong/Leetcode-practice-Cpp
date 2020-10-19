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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB == NULL) return NULL;
        ListNode* ptrA = headA;
        ListNode* ptrB = headB;
        while(1){
            if(ptrA == ptrB) break;
            ptrA = ptrA->next;
            ptrB = ptrB->next;
            if(ptrA == NULL && ptrB == NULL) break;
            if(ptrA == NULL) ptrA = headA;
            if(ptrB == NULL) ptrB = headB;
        }
        return ptrA;
    }
};