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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == NULL)    return {};
        
        vector<vector<int>> ans;
        queue<pair<TreeNode*, int>> bfs;

        bfs.push({root, 0});
        while(!bfs.empty()) {
            TreeNode* node = bfs.front().first;
            int level = bfs.front().second;
            bfs.pop();

            int currLevel = ans.size() == 0 ? 0 : ans.size()-1;
            if(level == 0) {
                ans.push_back({node->val});
            }else if(level == currLevel) {
                ans[currLevel].push_back(node->val);
            }else
                ans.push_back({node->val});
            
            if(node->left)
                bfs.push({node->left, level+1});
            if(node->right)
                bfs.push({node->right, level+1});
        }

        return ans;
    }
};
