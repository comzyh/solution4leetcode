class Solution {
public:
    bool dfs(const string &s, size_t rest_word, size_t pos, unordered_map<string, int> &avail_words) {
        if (rest_word == 0) {
            return true;
        }
        for (auto &w : avail_words) {
            if (w.second == 0) {
                continue;
            }
            const string &word = w.first;
            bool match = pos + word.size() <= s.size();
            if (match) {
                for (size_t i = 0; i < word.size(); i++) {
                    if (word[i] != s[pos + i]) {
                        match = false;
                        break;
                    }
                }
                if (match) {
                    avail_words[word] --;
                    if (dfs(s, rest_word - 1, pos + word.size(), avail_words)) {
                        return true;
                    }
                    avail_words[word] ++;
                }
            }

        }
        return false;
    }
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        size_t total_len = 0;
        unordered_map<string, int> word_count;
        for (auto &word : words) {
            total_len += word.size();
            word_count[word] ++;
        }
        for (size_t i = 0; i + total_len <= s.size(); i++) {
            unordered_map<string, int> word_count_copy(word_count.begin(), word_count.end());
            if (words.size() && dfs(s, words.size(), i, word_count_copy)) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
