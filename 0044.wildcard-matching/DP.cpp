#include <vector>
class Solution {
public:
    bool isMatch(string s, string p) {
        vector<bool> dp[2];
        dp[0].resize(p.size() + 1);
        dp[1].resize(p.size() + 1);
        dp[1][0] = 1;
        for (size_t i = 0; i < s.size(); i++) {
            int cur = i & 1;
            int pre = cur ^ 1;
            fill(dp[cur].begin(), dp[cur].end(), false);
            for (size_t j = 0; j < p.size(); j++) {
                if (!dp[pre][j]) {
                    continue;
                }
                if (p[j] == '*' ) {
                    dp[pre][j + 1] = true;
                    dp[cur][j] = true;
                    dp[cur][j + 1] = true;
                } else if (p[j] == '?' || s[i] == p[j]) {
                    dp[cur][j + 1] = true;
                }
            }
        }
        int cur = (s.size() & 1) ^ 1;
        for (size_t j = 0; j < p.size(); j++) {
            if (p[j] == '*' && dp[cur][j]) {
                dp[cur][j + 1] = true;
            }
        }
        return dp[cur][p.size()];
    }
};