class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2, -1);
        if (!nums.size()) {
            return ans;
        }
        int b = 0, e = nums.size() - 1;
        while (b <= e) {
            int mid = (b + e) / 2;
            if (nums[mid] < target) {
                b = mid + 1;
            } else if (nums[mid] > target) {
                e  = mid - 1;
            } else {
                break;
            }
        }
        if (b > e) {
            return ans;
        }
        int left = b, right = e;
        while (b < e) {
            int mid = (b + e) / 2;
            if (nums[mid] < target) {
                b = mid + 1;
            } else {
                e = mid;
            }
        }
        ans[0] = b;
        e = right;
        while (b < e) {
            int mid = (b + e + 1) / 2;
            if (nums[mid] <= target) {
                b = mid;
            } else {
                e = mid - 1;
            }
        }
        ans[1] = b;
        return ans;
    }
};
