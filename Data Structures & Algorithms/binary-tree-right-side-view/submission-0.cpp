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
    int level = 1;
    stack<pair<TreeNode*, int>> dfs;
    vector<int> rightView;
    void getRightView(TreeNode* root) {
        if(root == NULL)    return;

        TreeNode* node = dfs.top().first;
        int l = dfs.top().second;

        if(l > level){
            rightView.push_back(root->val);
            level = l;
        }
        
        if(node->right) {
            dfs.push({node->right, l+1});
            getRightView(root->right);
        }
        if(node->left) {
            dfs.push({node->left, l+1});
            getRightView(root->left);
        }

        dfs.pop();
    }

    vector<int> rightSideView(TreeNode* root) {
        if(root == NULL)    return {};

        rightView.push_back(root->val);
        dfs.push({root, 1});
        getRightView(root);

        return rightView;
    }
};
