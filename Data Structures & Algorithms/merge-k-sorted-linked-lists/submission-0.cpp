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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0)   return nullptr;

        vector<int> vec;
        for(auto&list:lists) {
            if(list == NULL)    continue;
            ListNode* node = list;
            while(node) {
                vec.push_back(node->val);
                node = node->next;
            }
        }
        
        if(vec.size() == 0)
            return nullptr;

        sort(vec.begin(), vec.end());

        ListNode* head = new ListNode(vec[0]);
        ListNode* node = head;
        for(int i=1;i<vec.size();i++) {
            ListNode* next = new ListNode(vec[i]);
            
            node->next = next;
            node = next;
        }

        return head;
    }
};
