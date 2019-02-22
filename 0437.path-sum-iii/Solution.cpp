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
    int RpathSum(TreeNode *root, unordered_map<int, int> &sums, int sum, int target) {
        if (root == nullptr) {
            return 0;
        }
        int ans = sums[sum + root->val - target];
        sums[sum + root->val] ++;
        ans += RpathSum(root->left, sums, sum + root->val, target);
        ans += RpathSum(root->right, sums, sum + root->val, target);
        sums[sum + root->val] --;
        return ans;
        
    }
    int pathSum(TreeNode* root, int sum) {
        unordered_map<int, int> sums;
        sums[0] = 1;
        return RpathSum(root, sums, 0, sum);
    }
};
