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
        queue<pair<TreeNode*, TreeNode*>> bfs;
        if(!p ^ !q) return false;

        bfs.push({p, q});
        while(!bfs.empty()) {
            pair<TreeNode*, TreeNode*> nodes = bfs.front();
            bfs.pop();

            TreeNode* pNode = nodes.first;
            TreeNode* qNode = nodes.second;
            if(!pNode && !qNode)    continue;
            if(!pNode ^ !qNode
            || (pNode->val != qNode->val)) return false;

            bfs.push({pNode->left, qNode->left});
            bfs.push({pNode->right, qNode->right});
        }

        return true;
    }
};









