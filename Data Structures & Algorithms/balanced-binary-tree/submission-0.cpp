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
    bool ans = true;

    int checkTree(TreeNode* &node){
        if(!node)   return 0;
        int hLeftTree = checkTree(node->left);
        int hRightTree = checkTree(node->right);

        if(abs(hLeftTree - hRightTree) > 1) ans = false;
        return max(hLeftTree, hRightTree) + 1;
    }

    bool isBalanced(TreeNode* root) {
        int h = checkTree(root);
        return ans;
    }
};
