class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 2) {
            return nums.size();
        }
        size_t pos = 0;
        int tmp[2];
        for (size_t i = 0; i < nums.size(); i++) {
            if (i < 2 || nums[i] != tmp[0]) {
                nums[pos ++] = nums[i];
            }
            tmp[0] = tmp[1];
            tmp[1] = nums[i];
        }
        nums.resize(pos);
        return pos;
    }
};
