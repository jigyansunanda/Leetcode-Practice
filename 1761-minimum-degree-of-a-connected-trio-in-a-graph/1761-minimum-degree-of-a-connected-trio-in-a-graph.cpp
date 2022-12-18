class Solution {
public:
    int minTrioDegree(int n, vector<vector<int>>& edges) {
        vector<int> g[n + 1];
        vector<int> deg(n + 1, 0);
        vector<vector<bool>> hasEdge(n+1, vector<bool>(n+1, false));
        for (auto &e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
            deg[e[0]]++; deg[e[1]]++;
            hasEdge[e[0]][e[1]] = true;
            hasEdge[e[1]][e[0]] = true;
        }
        int ans = INT_MAX;
        for (int a = 1; a <= n; ++a) {
            for (auto &b : g[a]) {
                for (auto &c : g[b]) {
                    if (hasEdge[a][c]) {
                        ans = min(ans, deg[a] + deg[b] + deg[c] - 6);
                    }
                }
            }
        }
        return (ans == INT_MAX) ? -1 : ans;
    }
};