class Solution {
public:
    void dfs(const string &s, string &tans, size_t pos, int ldel, int rdel, int stackl, unordered_set<string> &ans) {
        while (pos < s.size() && s[pos] != '(' && s[pos] != ')') {
            tans.push_back(s[pos]);
            pos ++;            
        }
        size_t size = tans.size();
        if (pos == s.size()) {
            if (stackl == 0 && ldel == 0 && rdel == 0) {
                ans.insert(tans);
            }
            return;
        }
        if (ldel + rdel > s.size() - pos || stackl > s.size() - pos) {
            return;
        }
        if (s[pos] == '(') {
            // del
            if (ldel) {
                dfs(s, tans, pos + 1, ldel - 1, rdel, stackl, ans);
                tans.resize(size);
            }
            // take
            tans.push_back('(');
            dfs(s, tans, pos + 1, ldel, rdel, stackl + 1, ans);
            tans.resize(size);
        }
        if (s[pos] == ')') {
            // del
            if (rdel) {
                dfs(s, tans, pos + 1, ldel , rdel - 1, stackl, ans);
                tans.resize(size);
            }
            // take
            if (stackl) {
                tans.push_back(')');
                dfs(s, tans, pos + 1, ldel, rdel, stackl - 1, ans);
                tans.resize(size);
            }
        }
    }
    vector<string> removeInvalidParentheses(string s) {
        stack<char> st;
        int rdel = 0;
        for (auto &c : s) {
            if (c == '(') {
                st.push(c);
            }
            if (c == ')') {
                if (st.size() && st.top() == '(') {
                    st.pop();
                } else {
                    rdel ++;
                }
            }
        }
        int ldel = st.size();
        unordered_set<string> ans;
        {
            string tmp;
            stack<char> tmps;
            dfs(s, tmp, 0, ldel, rdel, 0, ans);
        }
        return vector<string>(ans.begin(), ans.end());
    }
};
