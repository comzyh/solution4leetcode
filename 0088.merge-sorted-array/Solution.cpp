class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        nums1.resize(m + n);
        auto outit = nums1.rbegin();
        auto it1 = nums1.rbegin() + n;
        auto it2 = nums2.rbegin();
        for (; outit != nums1.rend(); outit++) {
            if (it2 == nums2.rend() || (it1 != nums1.rend() && *it1 > *it2)) {
                *outit = *it1;
                it1++;
            } else {
                *outit = *it2;
                it2++;
            }
        }
    }
};
