class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return 0;
        }
        vector<vector<int> > sum(matrix.size() + 1);
        for (size_t i = 0; i <= matrix.size(); i++) {
            sum[i].resize(matrix[0].size() + 1, 0);
        }
        for (size_t i = 0; i < matrix.size(); i++) {
            for (size_t j = 0; j < matrix[0].size(); j++) {
                sum[i + 1][j + 1] = (matrix[i][j] == '1') + sum[i][j + 1] + sum[i + 1][j] - sum[i][j];
            }
        }
        int rows = matrix.size();
        int cols = matrix[0].size();
        int ans = 0;
        for (int r1 = 1; r1 <= rows; r1 ++) {
            for (int r2 = r1; r2 <= rows; r2 ++){
                // liner
                int tans = 0;
                for (int c = 1; c <= cols; c++) {
                    if (sum[r2][c] - sum[r1 - 1][c] - sum[r2][c - 1] + sum[r1 - 1][c - 1] == r2 - r1 + 1) {
                        tans += r2 - r1 + 1;
                    } else {
                        tans = 0;                     
                    }
                    ans = max(ans, tans);
                }
            }
        }
        return ans;
        
    }
};
