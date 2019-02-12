class Solution {
public:
    int uniquePaths(int m, int n) {
        long long ans = 1; // Combin(m + n - 2, m - 1)
        m = m + n;
        n = min(n, m - n);
        m -= 2;
        n -= 1;
        for (int i = m - n + 1; i <= m; i++) {
            ans *= i;
        }
        for (int i = 1; i <= n; i++) {
            ans /= i;
        }
        return ans;
    }
};
