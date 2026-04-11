/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Codec {
public:
    TreeNode* makeTree(queue<string> &q) {
        string nodeVal = q.front();
        q.pop();
        if(nodeVal == "-")
            return NULL;

        TreeNode* node = new TreeNode(stoi(nodeVal));
        node->left = makeTree(q);
        node->right = makeTree(q);

        return node;
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == NULL)    return "-.";

        string ans = (to_string(root->val) + ".");
        ans += serialize(root->left);
        ans += serialize(root->right);

        return ans;
    }

    pair<string,int> getValue(string data, int ind) {
        string val = "";

        int i=ind;
        while(data[i] != '.') {
            val += data[i];
            i++;
        }

        return {val, i+1};
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        cout << "data: " << data << "\n";
        queue<string> q;
        pair<string, int> vali = getValue(data, 0);

        q.push(vali.first);
        int i = vali.second;
        while(i < data.size()) {
            vali = getValue(data, i);
            q.push(vali.first);
            i = vali.second;
        }

        TreeNode* root = makeTree(q);
        return root;
    }
};
