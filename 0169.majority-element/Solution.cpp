class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans = 0, count = 0;
        for (auto &n : nums) {
            if (n == ans) {
                count ++;
            } else {
                count --;
                if (count < 0) {
                    ans = n;
                    count = 1;
                }
            }
        }
        return ans;
    
    }
};
