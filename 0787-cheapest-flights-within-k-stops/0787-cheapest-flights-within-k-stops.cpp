class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        const int inf = 1e7;
        vector<pair<int, int>> g[n];
        for (auto &f : flights) g[f[0]].emplace_back(f[1], f[2]);
        vector<vector<int>> dp(k + 2, vector<int>(n, inf));
        dp[0][src] = 0;
        for (int edge = 1; edge <= k + 1; ++edge) {
            for (int node = 0; node < n; ++node) {
                if (dp[edge - 1][node] != inf) {
                    for (auto &next : g[node]) {
                        dp[edge][next.first] = min(dp[edge][next.first], dp[edge - 1][node] + next.second);
                    }
                }
            }
        }
        int ans = inf;
        for (int edge = 0; edge < k + 2; ++edge) {
            ans = min(ans, dp[edge][dst]);
        }
        return (ans == inf) ? -1 : ans;
    }
};