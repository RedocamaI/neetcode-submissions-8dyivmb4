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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1)  return list2;
        if(!list2)  return list1;
        
        ListNode* list3;
        ListNode* i = list1;
        ListNode* j = list2;

        if(i->val <= j->val){
            list3 = i;
            i = i->next;
            list3->next = NULL;
        }else{
            list3 = j;
            j = j->next;
            list3->next = NULL;
        }

        ListNode* k = list3;
        while(i && j){
            if(i->val <= j->val){
                k->next = i;
                i = i->next;
            }else{
                k->next = j;
                j = j->next;
            }
            
            k = k->next;
        }

        while(i){
            k->next = i;
            i = i->next;
            k = k->next;
        }

        while(j){
            k->next = j;
            j = j->next;
            k = k->next;
        }

        return list3;
    }
};
