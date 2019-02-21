class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        if (s.size() < p.size()) {
            return ans;
        }
        vector<int> pm(26);
        for (auto &c : p) {
            pm[c - 'a'] ++;
        }
        vector<int> sm(26);
        for (size_t i = 0; i < p.size(); i++) {
                sm[s[i] - 'a'] ++;
        }
        int match = 0;
        for (int i = 0; i < 26; i++) {
            match += pm[i] == sm[i];
        }
        if (match == 26) {
            ans.push_back(0);
        }
        for (size_t i = p.size(); i < s.size(); i++) {
            int del = s[i - p.size()] - 'a';
            sm[del] --;
            if (sm[del] == pm[del] - 1) {
                match --;
            }
            if (sm[del] == pm[del]) {
                match ++;
            }
            int ins = s[i] - 'a';
            sm[ins] ++;
            if (sm[ins] == pm[ins] + 1) {
                match --;
            }
            if (sm[ins] == pm[ins]) {
                match ++;
            }
            if (match == 26 ) {
                ans.push_back(i - p.size() + 1);
            }
            
        }
        return ans;
    }
};
