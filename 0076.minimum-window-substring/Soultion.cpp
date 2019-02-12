class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> sm, tm;
        unordered_set<char> enough, ts;
        for (auto &c : t) {
            tm[c] ++;
            ts.insert(c);
        }
        size_t l = 0;
        string ans;
        for (size_t i = 0; i < s.size(); i++) {
            sm[s[i]] ++;
            if (ts.count(s[i]) && sm[s[i]] >= tm[s[i]]) {
                enough.insert(s[i]);
            }
            while(sm[s[l]] > tm[s[l]] && l < s.size()) {
                sm[s[l]] --;
                l++;
            }
            // printf("l = %d, enough.size() = %lu, ts.size() = %lu\n", l, enough.size(), ts.size());
            if (enough.size() == ts.size() && (ans.size() == 0 || i - l + 1 < ans.size())) {
                ans = s.substr(l, i - l + 1);
            }
        }
        return ans;
    }
};
