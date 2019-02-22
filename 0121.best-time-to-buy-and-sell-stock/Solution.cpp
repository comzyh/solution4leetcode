class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minp = 0x3fffffff;
        int ans = 0;
        for (auto &p : prices) {
            ans = max(ans, p - minp);
            minp = min(minp, p);
        }
        return ans;
    }
};
