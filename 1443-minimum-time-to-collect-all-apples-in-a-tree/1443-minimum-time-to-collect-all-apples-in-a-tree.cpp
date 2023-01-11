class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<int> tree[n];
        for (auto &e : edges) {
            tree[e[0]].push_back(e[1]);
            tree[e[1]].push_back(e[0]);
        }
        auto dfs = [&](auto && dfs, int u, int p) -> int {
            int ans = 0;
            for (auto &v : tree[u]) {
                if (v != p) {
                    int subans = dfs(dfs, v, u);
                    if (subans or hasApple[v]) ans += (subans + 2);
                }
            }
            return ans;
        };
        return dfs(dfs, 0, -1);
    }
};