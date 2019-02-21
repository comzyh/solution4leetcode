class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size());
        int ans = 0;
        for (size_t i = 0; i < nums.size(); i++) {
            dp[i] = nums[i];
            if (i >= 2) {
                dp[i] += dp[i - 2];
            }
            if (i >= 1) {
                dp[i] = max(dp[i], dp[i - 1]);
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
