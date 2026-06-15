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
    bool hasCycle(ListNode *head) {
        ListNode *slow = head;
        if(slow == NULL) return false;
        ListNode *fast = head->next;
        while(fast!=NULL){
            if(fast==slow) return true;
            slow = slow->next;
            fast = fast->next;
            if(fast!=NULL){
                fast = fast->next;
            }
        }
        return false;
    }
};