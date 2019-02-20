class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        vector<int> dp[2];
        dp[0] = vector<int>(2001, 0);
        dp[1] = vector<int>(2001, 0);
        dp[1][1000] = 1;
        for (size_t i = 0; i < nums.size(); i++) {
            int n = nums[i];
            int cur = i & 1;
            int pre = cur ^ 1;
            fill(dp[cur].begin(), dp[cur].end(), 0);
            for (int j = 0; j <= 2000; j++) {
                if (j + n <= 2000 && dp[pre][j + n]) {
                    dp[cur][j] += dp[pre][j + n];
                }
                if (j - n >= 0 && dp[pre][j - n]) {
                    dp[cur][j] += dp[pre][j - n];
                }
            }
        }
        if (S > 1000 || S < -1000) {
            return 0;
        }
        return dp[(nums.size() & 1) ^ 1][1000 + S]; 
    }
};
