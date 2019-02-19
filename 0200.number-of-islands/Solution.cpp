const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.size() == 0 || grid[0].size() == 0) {
            return 0;
        }
        int ans = 0;
        for (size_t row = 0; row < grid.size(); row ++) {
            for (size_t col = 0; col < grid[0].size(); col ++) {
                if (grid[row][col] != '1') {
                    continue;
                }
                ans ++;
                queue<pair<int, int> > q;
                q.push(make_pair(int(row), int(col)));
                while(!q.empty()) {
                    pair<int, int> h = q.front();
                    q.pop();
                    grid[h.first][h.second] = '0';
                    for (int d = 0; d < 4; d++) {
                        int tx = h.first  + dx[d];
                        int ty = h.second + dy[d];
                        if (tx >= 0 && ty >= 0 && tx < grid.size() && ty < grid[0].size() && grid[tx][ty] == '1') {
                            q.push(make_pair(tx, ty));
                            grid[tx][ty] = '0';
                        }
                    }
                }
            }
        }
        return ans;
    }
};
