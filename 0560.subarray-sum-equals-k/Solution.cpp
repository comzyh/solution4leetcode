class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans = 0;
        unordered_map<int, int> so; // sum occur
        so[0] = 1;
        int sum = 0;
        for (size_t i = 0; i < nums.size(); i++) {
            sum += nums[i];
            ans += so[sum - k];
            so[sum] ++;
        }
        return ans;
    }
};
