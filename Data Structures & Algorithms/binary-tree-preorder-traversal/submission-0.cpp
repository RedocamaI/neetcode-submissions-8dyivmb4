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
    void getPreOrder(TreeNode* &root, vector<int>& preOrder) {
        if(!root)   return;

        preOrder.push_back(root->val);
        getPreOrder(root->left, preOrder);
        getPreOrder(root->right, preOrder);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preOrder;
        getPreOrder(root, preOrder);

        return preOrder;
    }
};