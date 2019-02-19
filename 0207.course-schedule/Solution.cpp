class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> req(numCourses, 0);
        vector<vector<int> > reverse(numCourses);
        for (auto &p : prerequisites) {
            req[p.first] ++;
            reverse[p.second].push_back(p.first);
        }
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (req[i] == 0) {
                q.push(i);
            }
        }
        int canfinish = 0;
        while (!q.empty()) {
            int h = q.front();
            q.pop();
            canfinish ++;
            for (auto &i : reverse[h]) {
                req[i] --;
                if (req[i] == 0) {
                    q.push(i);
                }
            }
        }
        return canfinish == numCourses;
    }
};
