class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(), 0x3fffffff);
        dp[0] = 0;
        for (size_t i = 0; i < nums.size(); i++) {
            for (int j = 1; j <= nums[i] && i + j < int(dp.size()); j++) {
                dp[i + j] = min(dp[i + j], dp[i] + 1);
            }
        }
        return dp[nums.size() - 1];
    }
};
