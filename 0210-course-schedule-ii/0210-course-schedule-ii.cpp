class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<int> g[n];
        vector<bool> visited(n, false), toBeFinished(n, false);
        vector<int> order;
        for (auto &e : pre) g[e[1]].push_back(e[0]);
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                bool ok = dfs(g, visited, toBeFinished, i, order);
                if (!ok) return {};
            }
        }
        reverse(order.begin(), order.end());
        return order;
    }

    bool dfs(vector<int> *g, vector<bool>& visited, vector<bool>& toBeFinished, int u, vector<int>& order) {
        if (toBeFinished[u]) return false;
        if (visited[u]) return true;
        toBeFinished[u] = visited[u] = true;
        for (auto &v : g[u]) {
            bool ok = dfs(g, visited, toBeFinished, v, order);
            if (!ok) return false;
        }
        toBeFinished[u] = false;
        order.push_back(u);
        return true;
    }
};