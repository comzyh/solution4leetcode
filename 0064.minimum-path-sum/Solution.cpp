class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int> > dp(grid.size());
        for (size_t i = 0; i < grid.size(); i++) {
            dp[i].resize(grid[0].size(), 0);
        }
        for (size_t row = 0; row < grid.size(); row ++) {
            for (size_t col = 0; col < grid[0].size(); col ++) {
                if (row == 0 && col == 0) {
                    dp[row][col] = grid[row][col]; 
                } else if (row == 0) {
                    dp[row][col] = grid[row][col] + dp[row][col - 1]; 
                } else if (col == 0) {
                    dp[row][col] = grid[row][col] + dp[row - 1][col]; 
                } else {
                    dp[row][col] = grid[row][col] + min(dp[row - 1][col], dp[row][col - 1]);
                }
            }
        }
        return dp[grid.size() - 1][grid[0].size() - 1];
    }
};
