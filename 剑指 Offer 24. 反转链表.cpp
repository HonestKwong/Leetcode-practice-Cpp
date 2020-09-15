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
    ListNode* reverseList(ListNode* head) {
//难度简单，运行效率96.18%
        stack<int> container;
        ListNode* tmp = head;
        ListNode* res = head;
        while(tmp!=NULL){
            container.push(tmp->val);
            tmp = tmp->next;
        }
        while(!container.empty()){
            res->val = container.top();
            container.pop();
            res = res->next;
        }
        return head;
    }
};