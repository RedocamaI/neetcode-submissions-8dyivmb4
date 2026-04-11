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
        int l = 0;
        if(!head->next) return;
        ListNode* node = head;

        while(node){
            l++;
            node = node->next;
        }
        if(l == 2)  return;

        int mid = l % 2 ? l/2 : l/2 - 1;
        node = head;
        ListNode* midNode;
        while(mid--){
            node = node->next;
        }
        midNode = node;
        node = node->next;

        stack<ListNode*> st;
        while(node){
            st.push(node);
            node = node->next;
        }

        ListNode* i = head;
        ListNode* j = i->next;
        while(!st.empty()){
            ListNode* k = st.top();
            st.pop();
            if(j == k)  break;

            i->next = k;
            k->next = j;
            i = j;
            j = j->next;            
        }
        if(l%2)    midNode->next = NULL;
        else    midNode->next->next = NULL;
    }
};
