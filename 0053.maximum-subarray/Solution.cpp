class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = -2147483647;
        int sum = 0;
        for (auto &n : nums) {
            sum += n;
            ans = max(ans, sum);
            if (sum < 0) {
                sum = 0;
            }
        }
        return ans;
    }
};
