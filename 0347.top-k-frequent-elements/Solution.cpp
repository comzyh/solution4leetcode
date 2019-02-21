class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for (auto &n : nums) {
            m[n] ++;
        }
        priority_queue<pair<int, int> > q;
        for (auto it = m.begin(); it != m.end(); it ++) {
            q.push(make_pair(-it->second, it->first));
            if (q.size() > k) {
                q.pop();
            }
        }
        vector<int> ans;
        while (!q.empty()) {
            ans.push_back(q.top().second);
            q.pop();
        }
        return ans;
    }
};
