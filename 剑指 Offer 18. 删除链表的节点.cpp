/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//效率77%，空间利用高，不是很好
class Solution1 {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        ListNode* p = head;
        ListNode* front = head;
        ListNode* q = head->next;
        if(head->val == val) return head->next; //直接返回下一个头节点
        p = p->next;
        q = q->next;
        while(p != NULL){
            if(p->val == val){
                front->next = p->next;
                p->next = NULL;
                return head;
            }
            p = p->next;
            q = q->next;
            front = front->next;
        }
        return head;
    }
};

//简化
class Solution2 {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        if(head->val == val) return head->next; //直接返回下一个头节点
        ListNode* p = head->next;
        ListNode* front = head;
        while(p != NULL){
            if(p->val == val){
                front->next = p->next;
                p->next = NULL;
                return head;
            }
            p = p->next;
            front = front->next;
        }
        return head;
    }
};

//一个指针！
class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        if(head->val == val) return head->next; //直接返回下一个头节点
        ListNode* p = head;
        while(p->next != NULL){
            if(p->next->val == val){
                p->next = p->next->next;
                return head;
            }
            p = p->next;
        }
        return head;
    }
};