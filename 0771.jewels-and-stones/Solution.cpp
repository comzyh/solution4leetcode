class Solution {
public:
    int numJewelsInStones(string J, string S) {
        unordered_set<char> jewel;
        for (auto &j : J) {
            jewel.insert(j);
        }
        int ans = 0;
        for (auto &s : S) {
            ans += jewel.count(s);
        }
        return ans;
    }
};
