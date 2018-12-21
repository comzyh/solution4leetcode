class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int mindis = 0x3fffffff, ans;
        sort(nums.begin(), nums.end());
        for (size_t mid = 0; mid < nums.size(); mid++) {
            size_t l = 0, r = nums.size() - 1;
            while (l < mid  && r > mid) {
                int sum = nums[l] + nums[mid] + nums[r];
                if (abs(sum - target) < mindis) {
                    mindis = abs(sum - target);
                    ans = sum;
                }
                if (sum - target < 0) {
                    l ++;
                } else {
                    r --;
                }
            }
        }
        return ans;
    }
};
