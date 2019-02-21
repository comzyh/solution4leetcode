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
    
    pair<int, int> robit(TreeNode *root) { // this, non-this 
        if (root == nullptr) {
            return make_pair(0 ,0);
        }
        pair<int, int> ans = make_pair(root->val, 0);
        if (root->left) {
            pair<int, int> tans = robit(root->left);
            ans.second += max(tans.first, tans.second);
            ans.first += tans.second;
        }
        if (root->right) {
            pair<int, int> tans = robit(root->right);
            ans.second += max(tans.first, tans.second);
            ans.first += tans.second;
        }
        return ans;
    }
    int rob(TreeNode* root) {
        pair<int, int> ans = robit(root);
        return max(ans.first, ans.second);
    }
};
