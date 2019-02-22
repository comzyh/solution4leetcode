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
    bool isLinkedSubtree(TreeNode *s, TreeNode *t) {
        if (s == nullptr && t == nullptr) {
            return true;
        }
        if (s == nullptr || t == nullptr) {
            return false;
        }
        if (s->val == t->val && isLinkedSubtree(s->left, t->left) && isLinkedSubtree(s->right, t->right) ) {
            return true;
        }
        return false;
    }
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if (s == nullptr && t == nullptr) {
            return true;
        }
        if (s == nullptr || t == nullptr) {
            return false;
        }
        if (s->val == t->val && isLinkedSubtree(s->left, t->left) && isLinkedSubtree(s->right, t->right) ) {
            return true;
        }
        if (isSubtree(s->left, t) || isSubtree(s->right, t)) {
            return true;
        }
        return false;
    }
};
