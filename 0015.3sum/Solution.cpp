class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int> > ans;
        sort(nums.begin(), nums.end());
        for (size_t mid = 0; mid < nums.size(); mid++) {
            if (mid > 1 && nums[mid] == nums[mid - 2]) {
                continue;
            }
            size_t l = 0, r = nums.size() - 1;
            if (mid > 0 && nums[mid] == nums[mid - 1]) {
                l = mid - 1;
            }
            while (l < mid && r > mid) {
                if (l > 0 && nums[l] == nums[l - 1]) {
                    l++;
                    continue;
                }
                int s = nums[l] + nums[mid] + nums[r];
                if (s == 0) {
                    ans.push_back(vector<int>{nums[l], nums[mid], nums[r]});
                    l ++;
                    continue;
                }
                if (s < 0) {
                    l ++;
                } else {
                    r --;
                }

            }            
        }
        return ans;
    }
};
