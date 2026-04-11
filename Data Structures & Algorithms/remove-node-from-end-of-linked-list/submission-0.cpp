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
        ListNode* node = head;
        int l = 0;
        while(node) {
            l++;
            node = node->next;
        }

        int x = l-n;
        node = head;
        if(x == 0)  return node->next;
        ListNode* prev = node;
        while(x--){
            prev = node;
            node = node->next;
        }

        prev->next = node->next;
        node->next = NULL;
        return head;
    }
};
