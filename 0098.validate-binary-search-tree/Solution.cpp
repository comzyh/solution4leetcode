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
    pair<int, int> maxminvalid(TreeNode *root, bool &valid) {
        pair<int, int> minmax = make_pair(root->val, root->val);
        if (root->left) {
            auto ret = maxminvalid(root->left, valid);
            if (ret.second >= root->val) {
                valid = false;
            }
            minmax.first = min(minmax.first, ret.first);
            minmax.second = max(minmax.second, ret.second);
        }
        if (root->right) {
            auto ret = maxminvalid(root->right, valid);
            if (ret.first <= root->val) {
                valid = false;
            }
            minmax.first = min(minmax.first, ret.first);
            minmax.second = max(minmax.second, ret.second);
        }
        return minmax;
    }
    bool isValidBST(TreeNode* root) {
        bool ans = true;
        if (root != nullptr) {
            maxminvalid(root, ans);
        }
        return ans;
    }
};
