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
    void kthSmallest(TreeNode* root, int k, int &num, int &ans) {
        if (root == nullptr) {
            return;
        }
        kthSmallest(root->left, k, num, ans);
        num ++;
        if (num == k) {
            ans = root->val;
        }
        kthSmallest(root->right, k, num, ans);
    }
    int kthSmallest(TreeNode* root, int k) {
        int ans, num = 0;
        kthSmallest(root, k, num, ans);
        return ans;
    }
};
