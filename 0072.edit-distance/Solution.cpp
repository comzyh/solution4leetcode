class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<int> dp[2];
        dp[0].resize(word2.size() + 1, 0);
        dp[1].resize(word2.size() + 1);
        for (int i = 0; i <= word2.size(); i++) {
            dp[0][i] = i;
        }
        for (size_t i = 0; i < word1.size(); i++) {
            int cur = (i + 1) & 1;
            int pre = cur ^ 1;
            // fill(dp[cur].begin(), dp[cur].end(), 0x3fffffff);
            for (size_t j = 0; j <= word2.size(); j++) {
                dp[cur][j] = dp[pre][j] + 1; // delete word 1
                if (j == 0) {
                    continue;
                }
                dp[cur][j] = min(dp[cur][j], dp[pre][j - 1] + 1);  // replace
                if (word1[i] == word2[j - 1]) { // no edit
                    dp[cur][j] = min(dp[cur][j], dp[pre][j - 1]); 
                }
                dp[cur][j] = min(dp[cur][j], dp[cur][j - 1] + 1);  // add
                
                
            }
        }
        return dp[word1.size() & 1][word2.size()];
    }
};
