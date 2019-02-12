class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.size() == 0) {
            return false;
        }
        int maxium = 0;
        for (int i = 0; i < int(nums.size()) && i <= maxium; i++) {
            maxium = max(maxium, i + nums[i]);
        }
        return maxium + 1 >= nums.size();
    }
};
