class Solution {
public:
    int trap(vector<int>& height) {
        stack<pair<int, int> > left; // <pos, height>
        stack<pair<int, int> > water; // <leftpos, water>
        vector<int> sum(height.size() + 1, 0);
        for (int i = 0; i < int(height.size()); i++) {
            int h = height[i]; 
            sum[i + 1] = sum[i] + h;
            while(left.size()) {
                auto l = left.top();
                pair<int, int> w = make_pair(l.first, min(l.second, h) * (i - l.first - 1) - (sum[i] - sum[l.first + 1]));
                while(water.size() && w.first <= water.top().first && w.second >= water.top().second) {
                    water.pop();
                }
                water.push(w);
                if (left.top().second > h) {
                    break;
                }
                left.pop();
            }
            left.push(make_pair(i, h));
        }
        int ans = 0;
        while (water.size()) {
            ans += water.top().second;
            // printf("l = %4d, water = %4d\n", water.top().first, water.top().second);
            water.pop();
        }
        return ans;
                     
        
    }
};
