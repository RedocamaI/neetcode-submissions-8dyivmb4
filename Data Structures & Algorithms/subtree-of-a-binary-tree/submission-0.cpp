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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!subRoot) {
            return true;
        }
        if (!root) {
            return false;
        }

        if (sameTree(root, subRoot)) {
            return true;
        }
        return isSubtree(root->left, subRoot) ||
               isSubtree(root->right, subRoot);
    }

    bool sameTree(TreeNode* root, TreeNode* sub) {
        if (!root && !sub)
            return true;

        queue<pair<TreeNode*, TreeNode*>> bfs;
        bfs.push({root, sub});
        
        while(!bfs.empty()) {
            TreeNode* lnode = bfs.front().first;
            TreeNode* rnode = bfs.front().second;

            bfs.pop();
            cout << "hi\n";
            if ((lnode == nullptr) != (rnode == nullptr)) 
                return false;
            if(!lnode && !rnode)    continue;
            if(lnode->val != rnode->val) return false;

            bfs.push({lnode->left, rnode->left});
            bfs.push({lnode->right, rnode->right});
        }

        return true;
    }
};