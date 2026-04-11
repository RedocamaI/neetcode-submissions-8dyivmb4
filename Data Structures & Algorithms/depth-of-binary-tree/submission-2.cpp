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
    int maxDepth(TreeNode* root) {
        if(!root)   return 0;

        queue<pair<int, TreeNode*>> q;
        q.push({1,root});
        int ans = 0;
        while(!q.empty()){
            TreeNode* node = q.front().second;
            int depth = q.front().first;
            ans = max(ans, depth);
            q.pop();

            if(node->left)  q.push({depth+1, node->left});
            if(node->right) q.push({depth+1, node->right});
        }

        return ans;
    }
};
