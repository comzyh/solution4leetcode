const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        if (matrix.size() == 0) {
            return ans;
        }
        pair<int, int> pos = make_pair(0, 0);
        int d = 0;
        int bx[2] = {-1, matrix.size()};
        int by[2] = {-1, matrix[0].size()};
        for (int i = 0; i < matrix.size() * matrix[0].size(); i++) {
            ans.push_back(matrix[pos.first][pos.second]);
            int tx = pos.first + dx[d];
            int ty = pos.second + dy[d];
            if (tx <= bx[0] || tx >= bx[1] || ty <= by[0] || ty >= by[1]) {
                switch (d) {
                    case 0:
                        bx[0] ++;
                        break;
                    case 1:
                        by[1] --;
                        break;
                    case 2:
                        bx[1] --;
                        break;
                    case 3:
                        by[0] ++;
                        break;
                }
                d = (d + 1) % 4;
                tx = pos.first + dx[d];
                ty = pos.second + dy[d];
            }
            pos = make_pair(tx, ty);
        }
        return ans;
    }
};
