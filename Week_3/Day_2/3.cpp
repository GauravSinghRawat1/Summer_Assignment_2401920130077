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
    bool isPalindrome(ListNode* head) {
        if (head == nullptr) {
            return true; 
        }

        int count = 0;
        ListNode* copy = head;
        while (copy != nullptr) {
            count = count + 1;
            copy = copy->next;
        } 
        
        if (count == 1) {
            return true;
        }
        
        if (count == 2) {
            return (head->val == head->next->val);
        }

        ListNode* prev = nullptr;
        ListNode* present = head;
        ListNode* next = head->next;

        for (int i = 0; i < count / 2; i++) {
            present->next = prev;
            prev = present;
            present = next;
            if (next != nullptr) {
                next = next->next;
            }
        }

        if (count % 2 == 0) {
            for (int i = 0; i < count / 2; i++) {
                if (prev->val != present->val) {
                    return false;
                }
                prev = prev->next;
                present = present->next;
            }
        } 
        else {
            for (int i = 0; i < count / 2; i++) {
                if (prev->val != next->val) {
                    return false;
                }
                prev = prev->next;
                next = next->next;
            }
        }
       
        return true;
    }
};