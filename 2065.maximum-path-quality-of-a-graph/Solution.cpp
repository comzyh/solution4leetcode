class Solution
{

public:
    void dfs(int x, int time, int value, vector<int> &edge_count, vector<int> &point_count,
             const vector<int> &values, const vector<vector<tuple<int, int, int>>> &tab, const vector<int> &mindis, const int maxTime, int &maxans)
    {
        if (time + mindis[x] > maxTime) // Can not make it to return
        {
            return;
        }
        int tv = value;
        if (point_count[x] == 0)
        {
            tv += values[x];
        }
        point_count[x]++;
        if (x == 0)
        {
            maxans = max(maxans, tv);
        }
        for (auto &e : tab[x])
        {
            auto t = std::get<0>(e);
            auto l = std::get<1>(e);
            auto index = std::get<2>(e);
            if (edge_count[index] >= 2)
            {
                continue;
            }
            edge_count[index]++;
            dfs(t, time + l, tv, edge_count, point_count, values, tab, mindis, maxTime, maxans);
            edge_count[index]--;
        }
        point_count[x]--;
    }
    int maximalPathQuality(vector<int> &values, vector<vector<int>> &edges, int maxTime)
    {
        vector<vector<tuple<int, int, int>>> tab(values.size()); // <target, length, index>
        for (size_t i = 0; i < edges.size(); i++)
        {
            auto &e = edges[i];
            int u = e[0];
            int v = e[1];
            int t = e[2];
            tab[u].push_back(make_tuple(v, t, i));
            tab[v].push_back(make_tuple(u, t, i));
        }
        // Get mindis
        priority_queue<pair<int, int>> q;
        vector<int> dis(values.size(), 0x3fffffff);
        dis[0] = 0;
        q.push(make_pair(0, 0));
        while (!q.empty())
        {
            auto h = q.top();
            q.pop();
            if (-h.first > dis[h.second])
            {
                continue;
            }
            for (auto &e : tab[h.second])
            {
                auto &t = std::get<0>(e);
                auto &l = std::get<1>(e);
                if (dis[h.second] + l < dis[t])
                {
                    dis[t] = dis[h.second] + l;
                    q.push(make_pair(-dis[t], t));
                }
            }
        }
        // DFS
        vector<int> edge_count(edges.size(), 0);
        vector<int> point_count(values.size(), 0);
        int ans = -1;
        dfs(0, 0, 0, edge_count, point_count, values, tab, dis, maxTime, ans);
        return ans;
    }
};
