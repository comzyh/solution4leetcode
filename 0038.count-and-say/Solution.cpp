class Solution {
public:
    string countAndSay(int n) {
        string ans = "1";
        for (int i = 2; i <= n; i++) {
            string tans;
            int count = 0;
            for (size_t j = 0; j < ans.size(); j++) {
                count ++;
                if (j == ans.size() - 1 || ans[j] != ans[j + 1]) {
                    tans.append(to_string(count));
                    tans += ans[j];
                    count = 0;
                }
            }
            ans = tans;
        }
        return ans;
    }
};
