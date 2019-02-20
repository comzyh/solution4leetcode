class Solution {
public:
    int quickselect(int *begin, int *end, int k) {
        if (end - begin == 1) {
            return *begin;
        }
        int mid = *(begin + (end - begin) / 2);
        int * l = begin, *r = end - 1;
        while (l <= r) {
            while(*l > mid) {
                l++;
            }
            while(*r < mid) {
                r --;
            }
            if (l <= r) {
                swap(*l, *r);
                l++;
                r--;
            }
        }
        if (r - begin + 1 >= k) {
            return quickselect(begin, r + 1, k);
        }
        return quickselect(r + 1, end, k - (r - begin + 1));
    }
    int findKthLargest(vector<int>& nums, int k) {
        return quickselect(nums.data(), nums.data() + nums.size(), k);
    }
};
