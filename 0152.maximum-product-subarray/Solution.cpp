class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = nums[0];
        int maxp = 1, minp = 1;
        for (auto &n : nums) {
            maxp *= n;
            minp *= n;
            if (n < 0) {
                swap(maxp, minp);
            }
            maxp = max(maxp, n);
            minp = min(minp, n);
            ans = max(ans, maxp);
        }
        return ans;
    }
};
