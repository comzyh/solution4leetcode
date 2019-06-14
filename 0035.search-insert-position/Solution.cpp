class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        // upper_bound
        size_t b = 0, e = nums.size();
        while (b < e) {
            int mid = (b + e) / 2;
            if (nums[mid] < target) {
                b = mid + 1;
            } else {
                e = mid;
            }
        }
        return b;
    }
};
