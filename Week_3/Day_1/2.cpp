/**
 * Definition for singly-linked list.
 * struct ListNode {
 * int val;
 * ListNode *next;
 * ListNode() : val(0), next(nullptr) {}
 * ListNode(int x) : val(x), next(nullptr) {}
 * ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr) {
            return head;
        }
        
        ListNode* prev = nullptr;
        ListNode* present = head;
        ListNode* next = present->next;
        
        while (present != nullptr) {
            present->next = prev;
            prev = present;
            present = next;
            if (next != nullptr) {
                next = next->next;
            }
        }
        
        return prev;
    }
};