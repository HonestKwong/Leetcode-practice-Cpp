/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//时间96% 空间48.6%
class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        stack<int> ans;
        vector<int> res;
        while(head!=NULL){
            ans.push(head->val);
            head = head->next;
        }
        while(!ans.empty()) {
            res.push_back(ans.top());
            ans.pop();
            }
        return res;
    }
};