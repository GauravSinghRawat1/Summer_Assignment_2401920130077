/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *prev = NULL;
        ListNode *curr = head;
        ListNode *next = head;
        int cnt = 1;
        while(cnt<=n){
            next = next->next;
            cnt+=1;
        }
        while(next){
            next = next->next;
            prev = curr;
            curr = curr->next;
        }
        if(prev == NULL){
            return head->next;
        }
        else{
            prev->next = curr->next;
        }
        return head;
    }
};