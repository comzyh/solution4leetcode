class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int x = 0; 2 * x < n; x++) {
            for (int y = x; y  < n - x - 1; y ++) {
                swap(matrix[x][y], matrix[y][n - 1 - x]);
                swap(matrix[n - 1 - y][x], matrix[x][y]);
                swap(matrix[n - 1 - x][n - 1 - y], matrix[n - 1 - y][x]);
            }
        }
    }
};
