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
    bool cycle(ListNode* node){
        if(!node)   return false;
        ListNode* fast = node;
        ListNode* slow = node;

        if(!fast->next) return false;
        fast = fast->next->next;
        slow = slow->next;
        while(fast && slow && fast != slow){
            if(!fast->next) return false;
            fast = fast->next->next;
            slow = slow->next;
        }

        if(fast && slow)    return fast == slow;
        return false;
    }

    bool hasCycle(ListNode* head) {
        return cycle(head);
    }
};
