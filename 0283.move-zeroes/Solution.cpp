class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int count = 0;
        int pos = 0;
        for (auto &n : nums) {
            if (n != 0) {
                nums[pos ++] = n;
            } else {
                count ++;
            }
        }
        for (int i = 0; i < count; i++) {
            nums[int(nums.size()) - 1 - i] = 0;
        }
    }
};
