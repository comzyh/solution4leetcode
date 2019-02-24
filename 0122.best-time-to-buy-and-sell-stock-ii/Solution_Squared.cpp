class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        vector<int> dp(prices.size(), 0);
        
        for (size_t i = 0; i < prices.size(); i++) {
            if (i > 0) {
                dp[i] = dp[i - 1];
            }
            for (int j = 0; j < i; j++) {
                int profit = prices[i] - prices[j];
                if (j > 0) {
                    profit += dp[j - 1];
                }
                ans = max(ans, profit);
                dp[i] = max(dp[i], profit);
            }
        }
        return ans;
    }
};
