class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        sort(people.begin(), people.end(), [](const pair<int, int> &a, const pair<int, int> &b)->bool {
            if (a.first != b.first) {
                return a.first > b.first;
            }
            return a.second < b.second;
        });
        vector<pair<int, int> > ans;
        for (auto &p : people) {
            auto it = ans.begin();
            int larger = 0;
            for (; it != ans.end() && larger < p.second; it ++, larger++) {
            }
            ans.insert(it, p);
        }
        return ans;
    }
};
