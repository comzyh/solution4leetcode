class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1.0;
        if (n < 0) {
            x = 1 / x;
            if (n == -2147483648) {
                ans *= x;
                n ++;
            }
            n = -n;
        }
        double mul = x;
        while (n) {
            if (n & 1) {
                ans *= mul;
            }
            mul = mul * mul;
            n >>= 1;
        }
        return ans;
    }
};
