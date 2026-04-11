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
    void reorderList(ListNode* head) {
        if(head->next && !head->next->next) return;

        // find the middle: hare & tortoise
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* mid;
        ListNode* prev;
        while(fast && fast->next){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        mid = fast ? slow->next : slow;
        if(fast){
            prev = slow;
            mid = slow->next;
        }else   mid = slow;
        
        // reverse 2nd-half of the linked list:
        ListNode* cur = mid;
        prev->next = NULL;
        while(cur){
            ListNode* next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }

        // two pointer approach:
        ListNode* i = head;
        ListNode* j = prev;
        while(i && i != j){
            ListNode* a = i->next;
            ListNode* b = j->next;

            i->next = j;
            j->next = a;

            if(i != b)  j = b;
            i = a;
        }
        j->next = NULL;
    }
};
