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
    bool check(TreeNode* root, TreeNode* sub) {
        queue<pair<TreeNode*, TreeNode*>> bfs;
        bfs.push({root, sub});

        while(!bfs.empty()) {
            TreeNode* lnode = bfs.front().first;
            TreeNode* rnode = bfs.front().second;

            bfs.pop();
            if ((lnode == nullptr) != (rnode == nullptr)) 
                return false;
            if(!lnode && !rnode)    continue;
            if(lnode->val != rnode->val) return false;

            bfs.push({lnode->left, rnode->left});
            bfs.push({lnode->right, rnode->right});
        }

        return true;
    }

    bool isSubtree(TreeNode* root, TreeNode* sub) {
        if(!sub)    return true;
        if(!root)   return false;

        if(check(root, sub))    return true;
        
        return isSubtree(root->left, sub) ||
            isSubtree(root->right, sub);
    }
};
