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
    ListNode* getKthFromEnd(ListNode* head, int k) {
        //这种解法实际上就是双指针
        ListNode* front = head;
        ListNode* back =head;
        for(int i =1;i<k;i++) back = back->next;
        while(back->next!=NULL){
            front = front->next;
            back = back->next;

        }
        return front;
    }
};