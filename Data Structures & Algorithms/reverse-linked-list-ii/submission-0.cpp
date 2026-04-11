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
    ListNode* getNode(ListNode* &head, int pos) {
        ListNode* node = head;
        while(pos--) {
            node = node->next;
        }

        return node;
    }
    
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* leftNode = getNode(head, left-1);
        ListNode* rightNode = getNode(head, right-1);
        ListNode* preLeft = NULL;
        ListNode* postRight = NULL;

        int preLeftInd = left-1;
        if(preLeftInd > 0) {
            ListNode* node = head;
            while(preLeftInd-- > 1)
                node = node->next;
            
            preLeft = node;
        }
        
        postRight = rightNode->next;
        ListNode* prev = NULL;
        ListNode* cur = leftNode;
        while(cur != postRight) {
            ListNode* next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }

        if(preLeft) {
            preLeft->next = rightNode;
        }else   head = rightNode;
        leftNode->next = postRight;

        return head;
    }
};