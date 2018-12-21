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
    TreeNode *flat(TreeNode *root) {
        if (root == nullptr) {
            return root;
        }
        TreeNode *tail = root;
        if (root->left != nullptr) {
            tail = flat(root->left);
        }
        if (root->right != nullptr) {
            tail->right = root->right;
            tail = flat(tail->right);
        }
        if (root->left) {
            root->right = root->left;    
        }
        root->left = nullptr;
        return tail;
    }
    void flatten(TreeNode* root) {
        flat(root);
    }
};
