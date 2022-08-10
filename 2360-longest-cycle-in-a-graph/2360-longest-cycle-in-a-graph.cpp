class Solution {
public:
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<int> g[n];
        for (int i = 0; i < n; ++i) {
            if (edges[i] != -1) {
                g[i].push_back(edges[i]);
            }
        }
        int longestCycleLength = 0;
        vector<bool> visited(n, false), callStack(n, false);
        vector<int> parent(n, -1);
        function<void(int, int)> dfs = [&](int u, int p) {
            visited[u] = true;
            callStack[u] = true;
            parent[u] = p;
            for (auto &v : g[u]) {
                if (!visited[v]) {
                    dfs(v, u);
                } else {
                    if (callStack[v] == true) {
                        int cycleLength = 1;
                        int node = u;
                        while (node != v) {
                            cycleLength++;
                            node = parent[node];
                        }
                        longestCycleLength = max(longestCycleLength, cycleLength);
                    }
                }
            }
            callStack[u] = false;
        };
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                dfs(i, i);
            }
        }
        return (longestCycleLength == 0) ? -1 : longestCycleLength;
    }
};