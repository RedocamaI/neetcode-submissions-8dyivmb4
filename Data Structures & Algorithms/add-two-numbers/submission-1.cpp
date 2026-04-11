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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode();
        ListNode* node = new ListNode();
        head->next = node;

        int carry = 0;
        while(l1 && l2) {
            int sum = l1->val + l2->val + carry;
            int val = sum%10;
            carry = sum > 9;
            
            node->val = val;
            if(l1->next || l2->next || carry) {
                ListNode* next = new ListNode();
                node->next = next;
                node = next;
            }

            l1 = l1->next;
            l2 = l2->next;
        }

        while(l1) {
            int sum = l1->val + carry;
            int val = sum%10;
            carry = sum > 9;

            node->val = val;
            if(l1->next || carry) {
                ListNode* next = new ListNode();
                node->next = next;
                node = next;
            }

            l1 = l1->next;
        }

        while(l2) {
            int sum = l2->val + carry;
            int val = sum%10;
            carry = sum > 9;

            node->val = val;
            if(l2->next || carry) {
                ListNode* next = new ListNode();
                node->next = next;
                node = next;
            }

            l2 = l2->next;
        }

        if(carry > 0) {
            node->val = carry;
        }

        return head->next;
    }
};
