class Solution {
public:
    int countSubstrings(string s) {
        vector<vector<char> > dp(s.size());
        int ans = s.size();
        for (size_t i = 0; i < s.size(); i++) {
            dp[i].resize(s.size());
            dp[i][i] = 1;
        }
        for (size_t l = 1; l < s.size(); l++) {
            for (size_t i = 0; i + l < s.size(); i++) {
                if (s[i] != s[i + l]) {
                    continue;
                }
                if (l == 1 || dp[i + 1][i + 1 + l - 2]) {
                    dp[i][i + l] = 1;
                    ans ++;
                }
            }
        }
        return ans;
    }
};
