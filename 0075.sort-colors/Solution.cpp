class Solution {
public:
    void sortColors(vector<int>& nums) {
        if (nums.size() == 0) {
            return;
        }
        int l = 0, r = nums.size() - 1;
        for (int i = 0; i <= r;) {            
            if (nums[i] == 0) {
                swap(nums[i], nums[l]);
                l ++;
                i ++;
            } else if (nums[i] == 2) {
                swap(nums[i], nums[r]);
                r --;
            } else {
                i++;
            }
        }
    }
};
