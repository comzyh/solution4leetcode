class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        const int dx[] = {0, 1, 0, -1};
        const int dy[] = {1, 0, -1, 0};
        vector<vector<int> > ans(n, vector<int>(n, 0));
        int x = 0, y = 0, d = 0;
        
        for (int i = 1; i <= n * n; i++) {
            ans[x][y] = i;
            while(i != n * n) {
                int tx = x + dx[d];
                int ty = y + dy[d];
                if (tx >= 0 && ty >= 0 && tx < n && ty < n && ans[tx][ty] == 0) {
                    x = tx;
                    y = ty;
                    break;
                } 
                d = (d + 1) % 4;
            }
        }
        return ans;
    }
};
