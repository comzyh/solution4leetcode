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
    int getDiamerter(TreeNode* root, int &ans) {
        if (root == nullptr) {
            return 0;
        }
        int l = getDiamerter(root->left, ans);
        int r = getDiamerter(root->right, ans);
        ans = max(ans, l + r);
        return max(l, r) + 1;
        
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        getDiamerter(root, ans);
        return ans;
    }
};
