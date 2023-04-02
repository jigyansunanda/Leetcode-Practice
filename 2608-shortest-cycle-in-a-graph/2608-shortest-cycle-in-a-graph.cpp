class Solution {
public:
    bool is_cycle = false;
    int min_cycle_length = INT_MAX;
    int stack[1001] = {0};
    int vis[1001] = {0};
    int par[1001];
    vector<vector<int>> g;

    void dfs(int u, int p) {
        vis[u] = 1;
        stack[u] = 1;
        par[u] = p;
        for (int v : g[u]) {
            if (!vis[v]) dfs(v, u);
            else if (stack[v] and v != p) {
                is_cycle = true;
                int curr_length = 1, node = u;
                while (node != v) {
                    node = par[node];
                    ++curr_length;
                }
                // debug(u, curr_length);
                min_cycle_length = min(min_cycle_length, curr_length);
            }
        }
        stack[u] = 0;
    }

    int findShortestCycle(int n, vector<vector<int>>& edges) {
        g.resize(n);
        memset(par, -1, sizeof par);
        for (auto& e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        for (int i = 0; i < n; ++i) {
            for (int i = 0; i < n; ++i) {
                vis[i] = false;
                stack[i] = false;
            }
            dfs(i, i);
        }
        return (!is_cycle) ? -1 : min_cycle_length;
    }
};