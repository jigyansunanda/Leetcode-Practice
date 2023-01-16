

class Solution {
public:
    long long maxOutput(int n, vector<vector<int>>& edges, vector<int>& price) {
        vector<int> tree[n];
        for (auto &e : edges) {
            tree[e[0]].push_back(e[1]);
            tree[e[1]].push_back(e[0]);
        }
        vector<long long> dp1(n, 0), dp2(n, 0), parent(n, -1);

        auto dfs1 = [&](auto && dfs1, int u, int p) -> long long {
            dp1[u] += price[u];
            parent[u] = p;
            for (int v : tree[u]) {
                if (v != p) {
                    long long childMax = dfs1(dfs1, v, u);
                    dp1[u] = max(dp1[u], price[u] + childMax);
                }
            }
            return dp1[u];
        };
        dfs1(dfs1, 0, -1);

        auto dfs2 = [&](auto && dfs2, int u, int p) -> void {
            if (u != 0) {
                dp2[u] = dp2[p] + price[p];
                for (int sibling : tree[p]) {
                    if (sibling != u and sibling != parent[p]) {
                        dp2[u] = max(dp2[u], price[p] + dp1[sibling]);
                    }
                }
            }
            for (int v : tree[u]) {
                if (v != p) dfs2(dfs2, v, u);
            }
        };
        dfs2(dfs2, 0, -1);

        
        long long ans = 0;
        for (int i = 0; i < n; ++i) {
            ans = max(ans, max(dp1[i], dp2[i]+price[i]) - (long long)price[i]);
        }
        return ans;
    }
};