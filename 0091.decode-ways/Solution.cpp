class Solution {
public:
    int numDecodings(string s) {
        int dp[2] = {0, 1};
        for (size_t i = 0; i < s.size(); i++) {
            int v = 0;
            if (s[i] - '0' != 0) {
                v += dp[1];
            }
            if (i > 0) {
                int t = (s[i - 1] - '0') * 10 + s[i] - '0';
                if (t >= 10 && t <= 26) {
                    v += dp[0];
                }
            }
            dp[0] = dp[1];
            dp[1] = v;
        }
        return dp[1];
    }
};
