class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return 0;
        }
        vector<vector<int> > dp(matrix.size());
        for (size_t i = 0; i < matrix.size(); i++) {
            dp[i].resize(matrix[0].size(), 0);
        }
        int ans = 0;
        for (size_t row = 0; row < matrix.size(); row ++) {
            for (size_t col = 0; col < matrix[0].size(); col ++) {
                if (matrix[row][col] == '0') {
                    continue;
                }
                int tans = 0;
                if (row > 0 && col > 0) {
                    tans = min(dp[row][col - 1], dp[row - 1][col]);
                    tans = min(tans, dp[row - 1][col - 1]);
                } else {
                    tans = 0;
                }
                tans ++;
                dp[row][col] = tans;
                ans = max(ans, tans * tans);
            }
        }
        return ans;
    }
};
