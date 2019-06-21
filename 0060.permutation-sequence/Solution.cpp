class Solution {
public:
    string getPermutation(int n, int k) {
        k --;
        vector<int> fact(n);
        fact[0] = 1;
        for (int i = 1; i < n; i++) {
            fact[i] = fact[i - 1] * i;
        }
        string ans;
        vector<int> used(n, 0);
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j < n; j ++) {
                if (used[j]) {
                    continue;
                }
                if (fact[i] <= k) {
                    k -= fact[i];
                } else {
                    ans += '1' + j;
                    used[j] = 1;
                    break;
                }
            }
        }
        return ans;
    }
};
