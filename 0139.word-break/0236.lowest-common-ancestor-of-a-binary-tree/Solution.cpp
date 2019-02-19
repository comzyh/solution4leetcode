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
    pair<bool, bool> LCA(TreeNode* root, TreeNode* p, TreeNode* q, TreeNode* &ans) {
        pair<bool, bool> tans = make_pair(false, false);
        if (root == p) {
            tans.first = true;
        }
        if (root == q) {
            tans.second = true;
        }
        if (root->left != nullptr) {
            pair<bool, bool> t = LCA(root->left, p, q, ans);
            tans.first |= t.first;
            tans.second |= t.second;
        }
        if (root->right != nullptr) {
            pair<bool, bool> t = LCA(root->right, p, q, ans);
            tans.first |= t.first;
            tans.second |= t.second;
        }
        if (tans.first && tans.second && ans == nullptr) {
            ans = root;
        }
        return tans;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr) {
            return nullptr;
        }
        TreeNode* ans = nullptr;
        LCA(root, p, q, ans);
        return ans;
    }
};
