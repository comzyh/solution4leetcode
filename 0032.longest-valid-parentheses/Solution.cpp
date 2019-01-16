class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        int ans = 0;
        for (auto &c : s) {
            if (c == '(') {
                st.push(-1);
            } else {
                int cur = 0;
                if (st.size() && st.top() > 0) {
                    cur = st.top();
                    st.pop();
                }
                if (st.size() && st.top() == -1) {
                    st.pop();
                    st.push(cur + 2);
                } else {
                    st.push(-2);
                }
                cur = 0;
                while (st.size() && st.top() > 0) {
                    cur += st.top();
                    st.pop();
                }
                ans = max(ans, cur);
                if (cur) {
                    st.push(cur);
                }

            }
        }
        return ans;
    }
};
