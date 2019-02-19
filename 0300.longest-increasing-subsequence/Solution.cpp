class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size() + 1, 0x3fffffff);
        int ans = 0;
        dp[0] = -2147483648;
        for (size_t i = 0; i < nums.size(); i++) {
            int p = lower_bound(dp.begin(), dp.begin() + i + 1, nums[i]) - dp.begin();
            ans = max(ans, p);
            dp[p] = min(dp[p], nums[i]);
        }
        return ans;
    }
};
