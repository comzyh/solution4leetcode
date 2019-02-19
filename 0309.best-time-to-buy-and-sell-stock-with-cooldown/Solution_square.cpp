class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> dp(prices.size(), 0);
        int ans = 0;
        for (int i = 0; i < int(prices.size()); i++) {
            if (i > 1) {
                dp[i] = dp[i - 1];
            }
            for (int j = 0; j < i; j++) {
                dp[i] = max(dp[i], prices[i] - prices[j] + (j - 2 >= 0 ? dp[j - 2] : 0));
                ans = max(ans, dp[i]);
            }
        }
        return ans;
    }
};
