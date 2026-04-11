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
        if(!h1) return nullptr;

        unordered_map<Node*, Node*> o2c;
        o2c[nullptr] = nullptr;
        
        Node* node = h1;
        while(node != nullptr) {
            if(o2c.find(node) == o2c.end())
                o2c[node] = new Node(0);
            o2c[node]->val = node->val;
            
            if(o2c.find(node->next) == o2c.end())
                o2c[node->next] = new Node(0);
            o2c[node]->next = o2c[node->next];

            if(o2c.find(node->random) == o2c.end())
                o2c[node->random] = new Node(0);
            o2c[node]->random = o2c[node->random];

            node = node->next;
        }

        return o2c[h1];
    }
};
