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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        queue<TreeNode*> bfs;
        bfs.push(root);
        while(!bfs.empty()) {
            TreeNode* node = bfs.front();
            bfs.pop();

            int val = node->val;
            int pval = p->val;
            int qval = q->val;

            if(val == pval || val == qval ||
            (val > pval && val < qval) ||
            (val < pval && val > qval)) return node;
            else if(val > pval && val > qval)
                bfs.push(node->left);
            else    bfs.push(node->right);
        }

        return root;
    }
};









