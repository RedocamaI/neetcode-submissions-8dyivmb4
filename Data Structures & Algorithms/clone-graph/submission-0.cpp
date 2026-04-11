/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* root) {
        if(!root)   return root;

        Node* deep = new Node(root->val);
        unordered_map<int, Node*> hash;
        queue<Node*> q;

        hash[deep->val] = deep;
        q.push(root);
        while(!q.empty()) {
            Node* node = q.front();
            Node* copy = hash[node->val];
            q.pop();

            vector<Node*> neighbors = node->neighbors;
            vector<Node*> copyNeighbors;
            for(auto& adj:neighbors) {
                Node* copyAdj;
                if(hash.find(adj->val) == hash.end()) {
                    copyAdj = new Node(adj->val);
                    q.push(adj);
                    hash[adj->val] = copyAdj;
                }

                copyAdj = hash[adj->val];
                copyNeighbors.push_back(copyAdj);
            }

            copy->neighbors = copyNeighbors;
        }

        return deep;
    }
};
