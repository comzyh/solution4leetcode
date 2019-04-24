class Solution {
public:
    int numDupDigitsAtMostN(int N) {
        // get digital
        vector<int> digital;
        {
            int n = N;
            int tans = 1;
            while (n) {
                digital.push_back(n % 10);
                n /= 10;
            }
        }
        int ans = 0;
        // leading zero
        {
            ans += digital.size() >= 2;
            int tans = 1;
            for (int i = 3; i <= int(digital.size()); i++) {
                tans *= 9 - (i - 3);
                ans += tans;
            }
            ans *= 9;
        }
        // get answer
        vector<bool> used(10, false);
        bool rep = false;
        for (int i = digital.size() - 1; i >= 0 && !rep; i --) {
            int candidate = 10 - (digital.size() - i);
            int free = i;
            int tans = 1;
            while (free--) {
                tans *= (candidate--);
            }
            for (int j = i + 1 == digital.size(); j < digital[i]; j ++) {
                if (!used[j]) {
                    ans += tans;
                }
            }
            rep |= used[digital[i]];
            used[digital[i]] = true;
        }
        ans += rep == false;
        return N - ans;

    }
};
