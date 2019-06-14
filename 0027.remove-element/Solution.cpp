class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        size_t pos = 0;
        for (size_t i = 0; i < nums.size(); i++) {
            if (nums[i] != val) {
                nums[pos ++] = nums[i];
            }
        }
        return pos;
    }
};
