class Solution {
public:
    int mySqrt(int x) {
        int b = 0, e = 46340;
        while (b < e) {
            int k = (b + e + 1) / 2;
            if (k * k > x) {
                e = k - 1;
            } else {
                b = k;
            }
        }
        return b;
    }
};
