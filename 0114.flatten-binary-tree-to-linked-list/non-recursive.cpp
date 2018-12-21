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
    void flatten(TreeNode* root) {
        TreeNode *cur = root;
        while(cur) {
            if (cur->left) {
                // find the right most node of cur->left
                TreeNode *right_most = cur->left;
                while(right_most->right) {
                    right_most = right_most->right;
                }
                // link cur->right to right most node
                right_most->right = cur->right;
                // replace cur->right with cur->left
                cur->right = cur->left;
                cur->left = nullptr;
            }
            cur = cur->right; // continue flatten
        }    
    }
};
