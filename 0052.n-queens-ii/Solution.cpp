class Solution {
public:
    int N, MASK;

    int find(int level, int right, int stright, int left) {
        if (level == N) {
            return 1;
        }
        right >>= 1;
        left = (left << 1) & MASK;
        int s = MASK ^ (right | stright | left);
        int ans = 0;
        while (s) {
            int bit = s & -s; // lowbit
            ans += find(level + 1, right | bit , stright | bit, left | bit);
            s ^= bit;
        }
        return ans;
    }
    int totalNQueens(int n) {
        N = n;
        MASK = (1 << N) - 1;
        return find(0, 0, 0, 0);
    }
};
