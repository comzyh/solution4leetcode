class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if (matrix.size() == 0) {
            return;
        }
        vector<int> rows(matrix.size(), 0), cols(matrix[0].size(), 0);
        for (size_t row = 0; row < matrix.size(); row ++) {
            for (size_t col = 0; col < matrix[0].size(); col ++) {
                if (matrix[row][col] == 0) {
                    rows[row] = 1;
                    cols[col] = 1;
                }
            }
        }
        for (size_t row = 0; row < matrix.size(); row ++) {
            for (size_t col = 0; col < matrix[0].size(); col ++) {
                if (rows[row] || cols[col]) {
                    matrix[row][col] = 0;
                }
            }
        }
    }
};
