class Solution {
public:
    bool search(vector<int>& nums, int target) {
        size_t b = 0, e = nums.size();
        while (b < e) {
            int mid = (b + e) / 2;
            if (nums[b] > target) {
                if (nums[mid] > nums[b] || nums[mid] < target) {
                    b = mid + 1;
                } else if (nums[mid] == nums[b]) {
                    while(b <= mid && nums[b] == nums[mid]) b++;
                } else {
                    e = mid;
                }
            } else if (nums[b] == target) {
                e = b;
            }
            else {
                if (nums[mid] > nums[b] && nums[mid] < target) {
                    b = mid + 1;
                } else if (nums[mid] == nums[b]) {
                    while(b <= mid && nums[b] == nums[mid]) b++;
                }else {
                    e = mid;
                }
            }
        }

        return b < nums.size() && nums[b] == target;
    }
};
