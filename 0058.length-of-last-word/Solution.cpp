class Solution {
public:
    int lengthOfLastWord(string s) {
        int ans = 0, l = 0;
        for (auto c : s) {
            if (c == ' ') {
                if (l) {
                    ans = l;
                }
                l = 0;
            } else {
                l ++;
            }
        }
        if (l) {
            ans = l;
        }
        return ans;
    }
};
