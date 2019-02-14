class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<pair<int, int> > q;
        vector<int> ans;
        
        for (size_t i = 0; i < nums.size(); i++) {
            while (!q.empty() && q.front().first < int(i) + 1 - k) {
               q.pop_front();
            }
            while(!q.empty() && q.back().second <= nums[i]) {
                q.pop_back();
            }
            q.push_back(make_pair(i, nums[i]));
            if (i >= k - 1) {
               ans.push_back(q.front().second);
            }
        }
        
        return ans;
    }
};
