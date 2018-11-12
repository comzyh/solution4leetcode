#include <algorithm>
using namespace std;
class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int b = 0, e = *(nums.rbegin()) - *(nums.begin());
        while (b < e) {
            int mid = (b + e) / 2;
            long long count = 0;
            auto tit = nums.begin();
            for (auto it = nums.begin(); it != nums.end(); it++) {
                // *tit >  *it + k
                // auto tit = upper_bound(it + 1, nums.end(), *it + mid);
                while(tit != nums.end() && ((tit - it) <= 0 ||  *tit <= *it + mid)) {
                    tit ++;
                }
                count += (tit - it) - 1;

            }
            if (count < k) {
                b = mid + 1;
            } else {
                e = mid;
            }
        }
        return b;
    }
};

