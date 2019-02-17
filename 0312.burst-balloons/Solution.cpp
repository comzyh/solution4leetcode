class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        vector<vector<int> > dp(nums.size());
        for (size_t i = 0; i < dp.size(); i++)  {
            dp[i].resize(nums.size());
        }
        for (int l = 0; l < n; l ++) {
            for (int i = 1; i + l <= n; i++){
                int j = i + l;
                for (int k = i; k <= j; k++) {
                    int tans = nums[k] * nums[i - 1] * nums[j + 1];
                    if (k > i) {
                        tans += dp[i][k - 1];
                    }
                    if (j > k) {
                        tans += dp[k + 1][j];
                    }
                    dp[i][j] = max(dp[i][j], tans);
                }
            }
        }
        return dp[1][n];
    }
};
