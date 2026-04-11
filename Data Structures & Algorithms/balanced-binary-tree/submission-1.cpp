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
    bool isBalanced(TreeNode* root) {
        return dfs(root)[0] == 1;
    }

    vector<int> dfs(TreeNode* &node) {
        if(!node)   return {1, 0};

        vector<int> left = dfs(node->left);
        vector<int> right = dfs(node->right);

        int lh = left[1];
        int rh = right[1];
        bool balanced = (left[0] && right[0]) &&
            abs(lh - rh) <= 1;
        int h = max(lh, rh) + 1;

        return {balanced ? 1 : 0, h};
    }
};
