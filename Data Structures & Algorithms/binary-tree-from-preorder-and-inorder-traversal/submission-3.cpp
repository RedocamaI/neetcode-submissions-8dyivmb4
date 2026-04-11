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

class Solution {
public:
    vector<int> preorder;
    int ind;
    unordered_map<int, int> ump;

    TreeNode* makeTree(int l, int r) {
        if(l > r)   return nullptr;

        int root_val = preorder[ind++];
        TreeNode* root = new TreeNode(root_val);

        int mid = ump[root_val];
        root->left = makeTree(l, mid-1);
        root->right = makeTree(mid+1, r);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        this->ind = 0;
        this->preorder = preorder;

        int n = inorder.size();
        for(int i=0;i<n;i++) {
            ump[inorder[i]] = i;
        }

        return makeTree(0, n-1);
    }
};
