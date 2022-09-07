class Solution {
public:
	int shortestPathLength(vector<vector<int>>& graph) {
		int n = graph.size();
		const int inf = 1e8;

		int dp1[13][13];
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				dp1[i][j] = inf;
			}
		}
		for (int u = 0; u < n; ++u) {
			for (int v : graph[u]) {
				dp1[u][v] = 1;
			}
			dp1[u][u] = 0;
		}
		for (int i = 0; i < n; ++i) {
			for (int u = 0; u < n; ++u) {
				for (int v = 0; v < n; ++v) {
					if (dp1[u][i] != inf and dp1[i][v] != inf) {
						dp1[u][v] = min(dp1[u][v], dp1[u][i] + dp1[i][v]);
					}
				}
			}
		}

		int dp2[13][(1 << 13) + 1];
		memset(dp2, -1, sizeof dp2);
		int ans = inf;
		int mask = (1 << n) - 1;

		function<int(int, int)> dfs = [&](int node, int Mask) {
			if (Mask == 0) return 0;
			if (dp2[node][Mask] != -1) return dp2[node][Mask];
			int res = inf;
			for (int v = 0; v < n; ++v) {
				if (Mask & (1 << v)) {
					res = min(res, dfs(v, Mask ^ (1 << v)) + dp1[node][v]);
				}
			}
			return dp2[node][Mask] = res;
		};

		for (int i = 0; i < n; ++i) {
			ans = min(ans, dfs(i, mask ^ (1 << i)));
		}
		return ans;
	}
};