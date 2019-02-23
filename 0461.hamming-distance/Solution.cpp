class Solution {
public:
    int hammingDistance(int x, int y) {
        int ans = 0;
        x ^= y;
        for (unsigned i = 1; i <= 1 << 30; i <<= 1) {
            ans += (x & i) > 0;
        }
        return ans;
    }
};
