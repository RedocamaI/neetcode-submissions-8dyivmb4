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
    int x;
    int ans;

    void getSmallest(TreeNode* root) {
        if(!root)   return;

        getSmallest(root->left);

        x--;
        if(x == 0) {
            ans = root->val;
            return;
        }

        if(x > 0)
            getSmallest(root->right);
    }

    int kthSmallest(TreeNode* root, int k) {
        this->x = k;

        getSmallest(root);
        return ans;
    }
};
