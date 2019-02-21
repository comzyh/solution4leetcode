class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size(), 1);
        int p = 1;
        for (size_t i = 0; i < nums.size(); i++) {
            ans[i] *= p;
            p *= nums[i];
        }
        p = 1;
        for (int i = int(nums.size()) - 1; i >= 0; i --) {
            ans[i] *= p;
            p *= nums[i];
        }
        return ans;
    }
};
