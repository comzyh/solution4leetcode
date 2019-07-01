class Solution {
public:
    bool basicCmp(string &s1, string &s2) {
        int count[26];
        fill(count, count + 26, 0);
        for (auto c: s1) {
            count[c - 'a'] ++;
        }
        for (auto c: s2) {
            count[c - 'a'] --;
        }
        for (int i = 0; i < 26; i++) {
            if (count[i]) {
                return false;
            }
        }
        return true;
    }
    bool isScramble(string s1, string s2) {
        if (!basicCmp(s1, s2)) {
            return false;
        }
        if (s1 == s2) {
            return true;
        }
        if (s1.length() == 1) {
            return false;
        }
        for (size_t i = 1; i < s1.size(); i++) {
            int l = i;
            int r = s1.size() - i;
            if (isScramble(s1.substr(0, l), s2.substr(0, l)) && isScramble(s1.substr(l, r), s2.substr(l, r)))  {
                return true;
            }
            if (isScramble(s1.substr(0, l), s2.substr(r, l)) && isScramble(s1.substr(l, r), s2.substr(0, r))) {
                return true;
            }
        }
        return false;

    }
};
