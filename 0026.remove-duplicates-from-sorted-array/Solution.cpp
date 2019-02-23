class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int pos = 0;
        for (size_t i = 0; i < nums.size(); i++) {
            if (i == 0 || nums[i] != nums[i - 1]) {
                nums[pos ++] = nums[i];
            }
        }
        nums.resize(pos);
        return pos;
    }
};
