class Solution {
    set<char> rows[9], cols[9], boxs[3][3];
public:
    bool dfs(int rest, vector<vector<char> >& board) {
        if (rest == 0) {
            return true;
        }
        pair<int, int> target = make_pair(-1, -1);
        vector<char> candidate(9);
        for (int x = 0; x < 9; x ++) {
            for (int y = 0; y < 9; y ++) {
                if (board[x][y] == '.') {
                    vector<char> tc(9);
                    auto it = set_intersection(rows[x].begin(), rows[x].end(), cols[y].begin(), cols[y].end(), tc.begin());
                    it = set_intersection(tc.begin(), it, boxs[x / 3][y / 3].begin(), boxs[x / 3][y / 3].end(), tc.begin());
                    tc.resize(it - tc.begin());
                    if (tc.size() &&  tc.size() < candidate.size()) {
                        target=make_pair(x, y);
                        candidate = tc;
                    } 
                }
            }
        }
        if (target.first == -1) {
            return false;
        }
        // printf("rest: %4d, x = %4d, y = %4d, candidate = %lu\n", rest, target.first, target.second, candidate.size());
        for (auto c: candidate) {
            int x = target.first, y = target.second;
            board[x][y] = c;
            rows[x].erase(c);
            cols[y].erase(c);
            boxs[x / 3][y / 3].erase(c);
            if (dfs(rest - 1, board)) {
                return true;
            }
            board[x][y] = '.';
            rows[x].insert(c);
            cols[y].insert(c);
            boxs[x / 3][y / 3].insert(c);
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            rows[i].clear();
            cols[i].clear();
            boxs[i / 3][i % 3].clear();
            for (int j = 0; j < 9; j++) {
                rows[i].insert('1' + j);
                cols[i].insert('1' + j);
                boxs[i / 3][i % 3].insert('1' + j);
            }
        }
        int rest = 81;
        for (int x = 0; x < 9; x++) {
            for (int y = 0; y < 9; y++) {
                if (board[x][y] != '.') {
                    rows[x].erase(board[x][y]);                    
                    cols[y].erase(board[x][y]);                    
                    boxs[x / 3][y / 3].erase(board[x][y]);
                    rest --;
                }            
            }
        }
        dfs(rest, board);
    }
};
