class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int profit[23] = {0, 0, 0};
        int mid = -2147483648;
        // dp[i] = max(dp[i], dp[i] + (profit[j - 2] - price[j]))
        for (int i = 0; i < int(prices.size()); i++) {
            profit[2] = profit[1];
            profit[1] = profit[0];
            profit[0] = max(profit[0], prices[i] + mid);
            mid = max(mid, profit[2] - prices[i]);
            ans = max(ans, profit[0]);
        }
        return ans;
    }
};
