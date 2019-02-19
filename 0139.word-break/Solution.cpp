class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if (s.size() == 0) {
            return false;
        }
        vector<char> dp(s.size(), 0);
        for (size_t i = 0; i < s.size(); i++) {
            if (i != 0 && dp[i - 1] == 0) {
                continue;
            }
            for (auto &word: wordDict) {
                if (i + word.size() > s.size() || dp[i + word.size() - 1] == 1) {
                    continue;
                }
                size_t j = 0;
                for (; j < word.size() && i + j < s.size() && word[j] == s[i + j]; j++);
                if (j == word.size()) {
                    dp[i + word.size() - 1] = 1;
                }
            }
        }
        return  dp[s.size() - 1] == 1;
    }
};
