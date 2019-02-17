/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    void Rserialize(TreeNode *root, string &ans) {
        if (root == nullptr) {
            return;
        }
        ans.append(std::to_string(root->val));
        ans.append(",");
        Rserialize(root->left, ans);
        ans.append(",");
        Rserialize(root->right, ans);
        ans.append(",");
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans;
        Rserialize(root, ans);
        cout << ans << endl;
        return ans;
    }

    int nextint(const char * &str) {
        int ans = 0;
        int flag = 1;
        if (*str == '-') {
            flag = -1;
            str++;
        }
        while(*str >= '0' && *str <= '9') {
            ans *= 10;
            ans += *str -'0';
            str++;
        }
        return ans * flag;
    }
    const char * Rdeserialize(TreeNode * &root, const char *str) {
        // cout << str << endl;
        if (*str == '\0') {
            return str;
        }
        int val = nextint(str);
        str++;
        root = new TreeNode(val);
        if (*str != ',') {
            str = Rdeserialize(root->left, str);
        }
        str ++;
       
        if (*str != ',') {
            str = Rdeserialize(root->right, str);
        }
        str ++;        
        return str;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        TreeNode *ans = nullptr;
        Rdeserialize(ans, data.data());
        return ans;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
