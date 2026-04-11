/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* h1) {
        if(!h1)    return nullptr;

        Node* org = h1;
        unordered_map<Node*, Node*> ump;
        Node* h2 = new Node(org->val);
        ump[org] = h2;

        Node* node = h2;
        while(org) {
            Node* nextOrg = org->next;
            Node* next = nextOrg ? 
                new Node(nextOrg->val) : nullptr;
            
            ump[nextOrg] = next;
            node->next = next;
            org = org->next;
            node = next;
        }

        node = h2;
        org = h1;
        while(node && org) {
            node->random = org->random ?
                (ump[org->random] ? 
                    ump[org->random] : new Node(org->random->val))
                : nullptr;
            
            node = node->next;
            org = org->next;
        }

        return h2;
    }
};
