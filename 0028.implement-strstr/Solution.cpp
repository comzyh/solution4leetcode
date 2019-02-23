class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.size() == 0) {
            return 0;
        }
        vector<int> dp(needle.size(), -1);
        int pos = -1;
        for (size_t i = 1; i < needle.size(); i++) {
            while(pos != -1 && needle[pos + 1] != needle[i]) {
                pos = dp[pos];
            }
            if (needle[pos + 1] == needle[i]) {
                pos ++;
            }
            cout << pos << endl;
            dp[i] = pos;
        }
        pos = -1;
        for (size_t i = 0; i < haystack.size(); i++) {
            while (pos != -1 && needle[pos + 1] != haystack[i]) {
                pos = dp[pos];
            }
            if(haystack[i] == needle[pos + 1]) {
                pos ++;
            }
            if (pos == needle.size() - 1) {
                return i + 1 - needle.size();
            }
        }
        return -1;
    }
};
