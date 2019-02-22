class Solution {
public:
    int abs(int n) {
        return n > 0 ? n : -n;
    }
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        for (auto &n : nums) {
            nums[abs(n) - 1] = -abs(nums[abs(n) - 1]);
        }
        vector<int> ans;
        for (size_t i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                ans.push_back(i + 1);
            }
        }
        return ans;
    }
};
