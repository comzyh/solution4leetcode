class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        vector<pair<int, int> > st;
        st.push_back(make_pair(-1, 0));
        int ans = 0;
        for (size_t i = 0; i < heights.size(); i++) {
            while (st.rbegin()->second >= heights[i] && st.size() > 1) {
                ans = max(ans, int(st.rbegin()->second * (i - (st.rbegin() + 1)->first - 1)));
                st.pop_back();
            }
            st.push_back(make_pair(i, heights[i]));
        }
        return ans;
    }
};