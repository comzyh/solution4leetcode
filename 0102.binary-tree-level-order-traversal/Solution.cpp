/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    void dfs(TreeNode *root, int level, vector<vector<int>> &ans) {
        if (level >= ans.size()) {
            ans.resize(level + 1);
        }
        ans[level].push_back(root->val);
        if (root->left) {
            dfs(root->left, level + 1, ans);
        }
        if (root->right) {
            dfs(root->right, level + 1, ans);
        }
    }
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root != nullptr) {
            dfs(root, 0, ans);
        }
        return ans;
    }
};
