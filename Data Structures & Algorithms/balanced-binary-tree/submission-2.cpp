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
    bool isBalanced(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode* node = root;
        unordered_map<TreeNode*, int> depth;
        TreeNode* last = nullptr;

        while(!st.empty() || node != nullptr) {
            if(node != nullptr){
                st.push(node);
                node = node->left;
            }else{
                node = st.top();
                if(node->right == nullptr || last == node->right){
                    st.pop();
                    int l = depth[node->left];
                    int r = depth[node->right];

                    if(abs(l-r) > 1)    return false;
                    int h = max(l, r) + 1;
                    depth[node] = h;
                    last = node;
                    node = nullptr;
                }else   node = node->right;
            }
        }

        return true;
    }
};
