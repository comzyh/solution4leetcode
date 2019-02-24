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
    TreeNode* sortedArrayToBST(int* start, int *end) {
        int* mid = start + (end - start) / 2;
     
        TreeNode* ans = new TreeNode(*mid);
        if (mid - start > 0) {
            ans->left = sortedArrayToBST(start, mid);
        }
        if (end - mid > 1) {
            ans->right = sortedArrayToBST(mid + 1, end);
        }
        return ans;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (!nums.size()) {
            return nullptr;
        }
        return sortedArrayToBST(nums.data(), nums.data() + nums.size());
    }
};
