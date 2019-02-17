class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, 0x7fffffff);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {
            for (auto &c: coins) {
                if (i - c >= 0 && dp[i - c] != 0x7fffffff) {
                    dp[i] = min(dp[i], dp[i - c] + 1);
                }
            }
        }
        if (dp[amount] != 0x7fffffff) {
            return dp[amount];
        }
        return -1;
    }
};
