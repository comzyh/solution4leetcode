class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> summary;
        for (auto &c : tasks) {
            summary[c] ++;
        }
        // pair<next_tick, -rest>
        priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > wait;
        priority_queue<int> ready;
        
        for (auto it = summary.begin(); it != summary.end(); it++) {
            wait.push(make_pair(0, it->second));
        }
        int tick = 0;
        while (!wait.empty() || !ready.empty()) {
            tick ++;
            if (ready.empty()) {
                tick = max(tick, wait.top().first);
            }
            while(!wait.empty() && wait.top().first <= tick) {
                ready.push(wait.top().second);
                wait.pop();
            }
            if (!ready.empty()) {
                int h = ready.top();
                ready.pop();
                if (h > 1) {
                    wait.push(make_pair(tick + 1 + n, h - 1));
                }
            }
        }
        return tick;
    }
};
