class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        //13:19
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return 0;
        }
        int ans = 0;
        vector<int> heights(matrix[0].size() + 1, 0);
        for (size_t row = 0; row < matrix.size(); row++) {
            stack<pair<int, int> > s;
            s.push(make_pair(-1, -1));
            for (int i = 0; i < int(heights.size()); i++) {
                if (i < matrix[row].size()) {
                    if (matrix[row][i] == '1') {
                        heights[i] ++;    
                    } else {
                        heights[i] = 0;    
                    }
                }
                while(heights[i] <= s.top().second) {
                    pair<int, int> t = s.top();
                    s.pop();
                    ans = max(ans, t.second * (i - s.top().first - 1));
                }
                s.push(make_pair(i, heights[i]));
            }
        }
        return ans;
    }
};
