class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int tmp = 0x80000000;
        for (auto &p: prices) {
            int profit = max(0, p + tmp);
            tmp = max(tmp, ans - p);
            ans = max(ans, profit);
        }
        return ans;        
    }
};
