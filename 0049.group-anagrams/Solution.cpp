class Solution {
public:
    string sortedstr(const string &s) {
        string str(s);
        sort(str.begin(), str.end());
        return str;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, int> m;
        vector<vector<string> > ans;
        for (auto &s: strs) {
            string ss = sortedstr(s);
            if (m.count(ss) == 0) {
                m.insert(make_pair(ss, m.size()));
                ans.push_back(vector<string>());
            }
            ans[m[ss]].push_back(s);
            
        }
        return ans;
    }
};
