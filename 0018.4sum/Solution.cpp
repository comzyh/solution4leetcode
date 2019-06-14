class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        set<tuple<int, int, int, int> > ans;
        sort(nums.begin(), nums.end());
        for (int i = 1; i + 2 < int(nums.size()); i++) {
            for (int j = i + 1; j + 1 < int(nums.size()); j++) {
                int t = target - nums[i] - nums[j];
                int l = i - 1;
                int r = j + 1;
                while (l >= 0 && r < int(nums.size())) {
                    int s = nums[l] + nums[r];
                    if (s == t) {
                        ans.insert(make_tuple(nums[l], nums[i], nums[j], nums[r]));
                    }
                    if (s > t) {
                        l--;
                    } else {
                        r++;
                    }
                }
            }
        }
        vector<vector<int> > ret;
        for (auto &t : ans) {
            ret.push_back(vector<int> {get<0>(t), get<1>(t), get<2>(t), get<3>(t)});
        }
        return ret;
    }
};
