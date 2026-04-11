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
    bool cycle(ListNode* node, unordered_map<ListNode*, int>& ump){
        if(!node)   return false;
        if(ump[node])   return true;
        ump[node]++;
        return cycle(node->next, ump);
    }

    bool hasCycle(ListNode* head) {
        unordered_map<ListNode*, int> ump;
        return cycle(head, ump);
    }
};
