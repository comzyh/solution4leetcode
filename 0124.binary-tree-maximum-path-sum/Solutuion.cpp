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
public:
    pair<int, int> maxPath(TreeNode* root) {
        pair<int, int> ans = make_pair(root->val, root->val);
        if (root ->left != nullptr) {
            auto tans = maxPath(root->left);
            ans.first = max(ans.first, ans.second + tans.second);
            ans.second = max(ans.second, tans.second + root->val);
            ans.first = max(ans.first, tans.first);
            
        }
        if (root ->right != nullptr) {
            auto tans = maxPath(root->right);
            ans.first = max(ans.first, ans.second + tans.second);
            ans.second = max(ans.second, tans.second + root->val);
            ans.first = max(ans.first, tans.first);
            
        }
        ans.first = max(ans.first, ans.second);
        return ans;
        
    }
    int maxPathSum(TreeNode* root) {
        auto ans = maxPath(root);
        return ans.first;
    }
};
