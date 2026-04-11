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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        stack<pair<TreeNode*, TreeNode*>> dfs;
        if(!p ^ !q) return false;

        dfs.push({p, q});
        while(!dfs.empty()) {
            pair<TreeNode*, TreeNode*> nodes = dfs.top();
            dfs.pop();

            TreeNode* pNode = nodes.first;
            TreeNode* qNode = nodes.second;
            if(!pNode && !qNode)    continue;
            if(!pNode ^ !qNode
            || (pNode->val != qNode->val)) return false;

            dfs.push({pNode->right, qNode->right});
            dfs.push({pNode->left, qNode->left});
        }

        return true;
    }
};









