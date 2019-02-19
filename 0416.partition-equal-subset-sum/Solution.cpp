class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (auto &n : nums) {
            sum += n;
        }
        if (sum % 2 == 1) {
            return false;
        }
        vector<int> dp(sum / 2 + 1, 0);
        dp[0] = 1;
        for (auto n : nums) {
            for (int i = sum / 2; i >= 1 ; i--) {
                if (i >= n && dp[i - n]) {
                    dp[i] = 1;
                }
            }
        }
        return dp[sum / 2] == 1;
    }
};
