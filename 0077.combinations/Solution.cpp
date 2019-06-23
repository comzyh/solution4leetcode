class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int> > ans;
        vector<int> t(k, 0);
        int i = 0;
        while (i >= 0) {
            if (i == k) {
                ans.push_back(t);
                i--;
                continue;
            }
            t[i] ++;
            if(t[i] > n) {
                i--;
                continue;
            }
            i++;
            if(i < k) {
                t[i] = t[i - 1];
            }
        }
        return ans;
    }
};
