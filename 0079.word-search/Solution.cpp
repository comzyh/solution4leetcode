const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};
class Solution {
public:
    bool search(vector<vector<char>>& board, vector<vector<bool>>& used, const char *word, int x, int y) {
        if (*word != board[x][y]) {
            return false;
        }
        if (*(word + 1) == '\0') {
            return true;
        }
        used[x][y] = true;
        for (int d = 0; d < 4; d++) {
            int tx = x + dx[d];
            int ty = y + dy[d];
            if (tx >= 0 && ty >= 0 && tx < board.size() && ty < board[0].size() && !used[tx][ty]) {
                if (search(board, used, word + 1, tx, ty)) {
                    used[x][y] = false;
                    return true;
                }
            }
        }
        used[x][y] = false;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        if (board.size() == 0 || board[0].size() == 0) {
            return false;
        }
        vector<vector<bool> > used(board.size());
        for (size_t i = 0; i < board.size(); i++) {
            used[i].resize(board[0].size(), false);
        }
        bool ans = false;
        for (size_t i = 0; i < board.size() && !ans; i++) {
            for (size_t j = 0; j < board[0].size() && !ans; j++) {
                ans |= search(board, used, word.data(), i, j);
            }
        }
        return ans;
    }
};
