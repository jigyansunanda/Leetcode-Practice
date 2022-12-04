class Solution {
public:
    int ans;

    int minScore(int n, vector<vector<int>>& roads) {
        vector<pair<int, int>> g[n + 1];
        for (auto &r : roads) {
            g[r[0]].emplace_back(r[1], r[2]);
            g[r[1]].emplace_back(r[0], r[2]);
        }
        ans = 1e7;
        vector<bool> vis(n + 1, false);
        dfs(g, 1, vis);
        return (ans == 1e7) ? -1 : ans;
    }

    void dfs(vector<pair<int, int>> *g, int u, vector<bool>& vis) {
        vis[u] = true;
        for (auto child : g[u]) {
            int v = child.first;
            int d = child.second;
            ans = min(ans, d);
            if (!vis[v]) {
                dfs(g, v, vis);
            }
        }
    }
};