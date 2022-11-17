class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<int> g[n];
        vector<bool> visited(n, false), toBeFinished(n, false);
        for (auto &e : pre) g[e[1]].push_back(e[0]);
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                bool ok = dfs(g, visited, toBeFinished, i);
                if (!ok) return false;
            }
        }
        return true;
    }

    bool dfs(vector<int> *g, vector<bool>& visited, vector<bool>& toBeFinished, int u) {
        if (toBeFinished[u]) return false;
        if (visited[u]) return true;
        toBeFinished[u] = visited[u] = true;
        for (auto &v : g[u]) {
            bool ok = dfs(g, visited, toBeFinished, v);
            if (!ok) return false;
        }
        toBeFinished[u] = false;
        return true;
    }
};