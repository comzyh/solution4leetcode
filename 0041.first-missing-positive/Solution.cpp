class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for (size_t i = 0; i < nums.size(); i++) {
            while (nums[i] != i + 1) {
                if (nums[i] > 0 && nums[i] <= nums.size()) {
                    int t = nums[i];
                    if (nums[t - 1] == nums[i]) {
                        break;
                    }
                    swap(nums[i], nums[t - 1]);
                } else {
                    break;
                }
            }
        }
        for (size_t i = 0;i < nums.size(); i++) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }
        return nums.size() + 1;
    }
};
