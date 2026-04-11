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
    int maxSum;
    int getMaxPathSum(TreeNode* root) {
        if(root == NULL)
            return 0;
        
        int left = getMaxPathSum(root->left);
        int right = getMaxPathSum(root->right);

        maxSum = max({root->val + left + right, root->val + left,
            root->val + right, root->val, maxSum});
        
        return max({root->val, root->val + left, root->val + right});
    }
    
    int maxPathSum(TreeNode* root) {
        this->maxSum = -1e9;

        int val = getMaxPathSum(root);

        return maxSum;
    }
};
