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
    int goodNodes(TreeNode* root) {
        stack<pair<TreeNode*, TreeNode*>> dfs;
        dfs.push({root, root});
        int ans = 0;

        while(!dfs.empty()) {
            TreeNode* node = dfs.top().first;
            TreeNode* max = dfs.top().second;
            dfs.pop();

            if(node == max) ans++;

            TreeNode* maxNode;
            if(node->right) {
                maxNode = node->right->val >= max->val ?
                    node->right : max;
                
                dfs.push({node->right, maxNode});
            }
            if(node->left) {
                maxNode = node->left->val >= max->val ?
                    node->left : max;
                
                dfs.push({node->left, maxNode});
            }
        }

        return ans;
    }
};
