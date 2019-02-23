class Solution {
public:
    int divide(int dividend, int divisor) {
        if(divisor == 0 || (dividend == -2147483648 && divisor == -1)) {
            return 0x7fffffff;
        }
        if (divisor == -2147483648) {
            return dividend == -2147483648;
        }
        if (divisor == 1) {
            return dividend;
        }
        int flag = 1;
        int ans = 0, sum = 0;
        if (dividend < 0 || divisor < 0) {
            flag = -1;
        }
        if (dividend < 0 && divisor < 0) {
            flag = 1;
        }
        if (divisor < 0) {
            divisor = -divisor;
        }
        if (dividend < 0) {
            if (dividend == -2147483648) {
                dividend += divisor;
                ans ++;
            }
            dividend = -dividend;
        }
        while (sum <= dividend - divisor) {
            int add = divisor, bit = 1;
            while(sum <= dividend - add) {
                sum += add;
                ans += bit; 
                if (add < 0x40000000) {
                    add += add;
                    bit += bit;
                } else {
                    break;
                }
            }
        }
        return ans * flag;
        
        
    }
};
