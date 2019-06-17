class Solution {
public:
    int N, MASK;
    void find(int level, int right, int stright, int left, vector<int> &state, vector<vector<string> > & res) {
        if (level == N) {
            vector<string> ans;
            for (int l = 0; l < N; l ++) {
                string line(N, '.');
                for (int i = 0; i < N; i++) {
                    if (state[l] & (1 << i)) {
                        line[i] = 'Q';
                    }
                }
                ans.push_back(line);
            }
            res.push_back(ans);
            return;
        }
        right >>= 1;
        left = (left << 1) & MASK;
        int s = MASK ^ (right | stright | left);
        while (s) {
            int bit = s & -s; // lowbit
            state[level] = bit;
            find(level + 1, right | bit , stright | bit, left | bit, state, res);
            s ^= bit;
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        N = n;
        MASK = (1 << N) - 1;
        vector<int> state(N);
        vector<vector<string> > res;
        find(0, 0, 0, 0, state, res);
        return res;
    }
};
