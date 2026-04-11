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
    stack<TreeNode*> dfs;

    void inOrder(TreeNode* root) {
        if(!root)   return;
        
        inOrder(root->right);
        dfs.push(root);
        inOrder(root->left);
    }

    int kthSmallest(TreeNode* root, int k) {
        inOrder(root);

        k--;
        while(!dfs.empty() && k--) {
            dfs.pop();
        }

        return dfs.top()->val;
    }
};
