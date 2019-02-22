class Solution {
public:
    int climbStairs(int n) {
        int dp[2] = {0, 1};
        for (int i = 0; i < n; i++) {
            int t = dp[0] + dp[1];
            dp[0] = dp[1];
            dp[1] = t;
        }
        return dp[1];
    }
};
