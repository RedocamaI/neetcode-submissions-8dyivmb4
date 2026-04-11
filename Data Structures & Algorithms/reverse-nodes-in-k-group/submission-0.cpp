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
    int k;
    ListNode* front;
    ListNode* prevFront = NULL;
    ListNode* ans;

    void reverseGroup(ListNode*& node, ListNode* prev) {
        front = node;
        int k = this->k;

        while(k--) {
            ListNode* next = node->next;
            node->next = prev;
            prev = node;
            node = next;
        }

        if(prevFront)   prevFront->next = prev;
        else    ans = prev;
        front->next = node;
        prevFront = front;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        int l = 0;
        this->k = k;
        ListNode* node = head;

        while(node) {
            l++;
            node = node->next;
        }

        int grps = l/k;
        this->ans = head;
        ListNode* prev = NULL;
        node = head;
        for(int i=0;i<grps;i++) {
            prev = NULL;
            reverseGroup(node, prev);
        }

        return ans;
    }
};
