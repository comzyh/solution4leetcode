class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, 0x3fffffff);
        dp[0] = 0;
        for (int v = 1; v * v <= n; v++) {
            for (int i = v * v; i <= n; i++) {
                if (dp[i - v * v] < 0x3fffffff) {
                    dp[i] = min(dp[i], dp[i - v * v] + 1);
                }
            }
        }
        return dp[n];
    }
};
