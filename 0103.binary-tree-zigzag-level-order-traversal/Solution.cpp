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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int> > ans;
        queue<pair<TreeNode*, int> > q;
        q.push(make_pair(root, 1));
        while (!q.empty()) {
            auto h = q.front();
            q.pop();
            if (h.first == nullptr) {
                continue;
            }
            if (h.second > ans.size()) {
                ans.resize(h.second);
            }
            ans[h.second - 1].push_back(h.first->val);
            q.push(make_pair(h.first->left, h.second + 1));
            q.push(make_pair(h.first->right, h.second + 1));
        }
        for (size_t i = 1; i < ans.size(); i += 2) {
            std::reverse(ans[i].begin(), ans[i].end());
        }
        return ans;
    }
};
