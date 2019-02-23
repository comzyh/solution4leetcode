class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<int> rows[9], cols[9], boxs[9];
        for (int i = 0; i < 9; i++) {
            rows[i].resize(9, 0);
            cols[i].resize(9, 0);
            boxs[i].resize(9, 0);
        }
        for (int row = 0; row < 9; row ++) {
            for (int col = 0; col < 9; col ++) {
                if (board[row][col] == '.') continue;
                int n = board[row][col] - '1';
                if (++rows[row][n] > 1) return false;
                if (++cols[col][n] > 1) return false;
                if (++boxs[row - (row % 3) + (col / 3)][n] > 1) return false;
            }
        }
        return true;
    }
};
