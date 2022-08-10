class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<int> g[n];
        for (auto &e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        vector<long long> A;
        long long components = 0;
        vector<bool> vis(n, false);
        function<void(int)> dfs = [&](int u) {
            vis[u] = true;
            components++;
            for (auto &v : g[u]) {
                if (!vis[v]) {
                    dfs(v);
                }
            }
        };
        for (int i = 0; i < n; ++i) {
            if (!vis[i]) {
                components = 0;
                dfs(i);
                A.push_back(components);
            }
        }
        long long sum = accumulate(A.begin(), A.end(), 0ll);
        long long ans = 0;
        for (int i = 0; i < A.size(); ++i) {
            ans += (A[i] * (sum - A[i]));
        }
        ans /= 2;
        return ans;
    }
};