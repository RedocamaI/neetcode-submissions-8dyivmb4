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
    int ind;
    unordered_map<int, int> ump;
    vector<int> preorder;
    vector<int> inorder;

    TreeNode* makeTree(int l, int r) {
        if(l > r)   return nullptr;

        int rootVal = preorder[ind++];
        TreeNode* root = new TreeNode(rootVal);
        int mid = ump[rootVal];
        root->left = makeTree(l, mid-1);
        root->right = makeTree(mid+1, r);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        this->ind = 0;
        this->preorder = preorder;
        this->inorder = inorder;

        for(int i=0;i<n;i++) {
            ump[inorder[i]] = i;
        }

        return makeTree(0, n-1);
    }
};
