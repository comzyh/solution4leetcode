class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (!nums.size()) {
            return -1;
        }
        int b = 0, e = nums.size() - 1;
        while (b < e) {
            int mid = (b + e) / 2;
            if (nums[mid] < nums[b]) {
               if (target <= nums[e] && target >= nums[mid]) {
                   b = mid;
               } else {
                   e = mid - 1;
               }
            } else if (nums[mid] > nums[e]) {
                if (target >= nums[b] && target <= nums[mid]) {
                    e = mid;
                } else {
                    b = mid + 1;
                }
            } else {
                if (target > nums[mid]) {
                    b = mid + 1;
                } else {
                    e = mid;
                }
            }
            
        }
        if (nums[b] == target) {
            return b;
        }
        return -1;
    }
};
