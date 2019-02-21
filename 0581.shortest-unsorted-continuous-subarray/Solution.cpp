class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        vector<int> tosort(nums.begin(), nums.end());
        sort(tosort.begin(), tosort.end());
        int b = 0, e = nums.size() - 1;
        for (;b < nums.size() && nums[b] == tosort[b]; b++);
        for (;e >= 0 && nums[e] == tosort[e]; e--);
        return max(e - b + 1, 0);
    }
};
