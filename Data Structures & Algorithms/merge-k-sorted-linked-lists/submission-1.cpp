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
    priority_queue<
        pair<int, ListNode*>,
        vector<pair<int, ListNode*>>,
        greater<pair<int, ListNode*>>
    > mnhp;

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0)   return nullptr;

        for(auto& list:lists) {
            mnhp.push({list->val, list});
        }

        ListNode* head = new ListNode(0);
        ListNode* node = head;
        while(!mnhp.empty()) {
            ListNode* min = mnhp.top().second;
            int val = mnhp.top().first;
            mnhp.pop();

            ListNode* next = new ListNode(val);
            node->next = next;
            node = next;

            if(min->next)
                mnhp.push({min->next->val, min->next});
        }

        return head->next;
    }
};







