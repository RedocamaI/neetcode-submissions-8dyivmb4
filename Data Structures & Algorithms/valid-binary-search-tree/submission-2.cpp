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
    bool checkBST(TreeNode* root, int mx, int mn) {
        if(root == NULL)    return true;
        if(root->val <= mn || root->val >= mx)
            return false;
        
        bool left = true;
        if(root->left) {
            int val = root->left->val;
            if(root->val <= root->left->val)    return false;

            left = checkBST(root->left, root->val, mn);
        }
        if(!left)   return left;

        bool right = true;
        if(root->right) {
            if(root->val >= root->right->val)   return false;

            right = checkBST(root->right, mx, root->val);
        }

        return left && right;
    }

    bool isValidBST(TreeNode* root) {
        return checkBST(root, 1001, -1001);
    }
};
