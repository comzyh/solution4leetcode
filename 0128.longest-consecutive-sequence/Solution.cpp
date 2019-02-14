class Solution {
    unordered_set<int> nums_set;
    unordered_map<int, int> cons;
public:
    int get_cons(int x) {
        if (!nums_set.count(x)) {
            return 0;
        }
        if (!cons.count(x)) {
         cons[x] = get_cons(x + 1) + 1;   
        }
        return cons[x];
        
    }
    int longestConsecutive(vector<int>& nums) {
        nums_set.clear();
        cons.clear();
        for (auto &num : nums) {
            nums_set.insert(num);
        }
        int ans = 0;
        for (auto &num : nums) {
            ans = max(ans, get_cons(num));
        }
        return ans;
        
    }
};
