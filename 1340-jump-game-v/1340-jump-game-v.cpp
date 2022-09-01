class Solution {
public:
	int maxJumps(vector<int>& arr, int d) {
		int n = arr.size();
		vector<int> g[n];
		for (int i = 0; i < n; ++i) {
			for (auto j = i + 1; j <= min(i + d, (int)arr.size() - 1) && arr[j] < arr[i]; ++j) {
				g[i].push_back(j);
			}
			for (auto j = i - 1; j >= max(0, i - d) && arr[j] < arr[i]; --j) {
				g[i].push_back(j);
			}
		}
		vector<bool> vis(n, false);
		vector<int> dp(n, 0);
		function<void(int)> dfs = [&](int u) {
			vis[u] = true;
			for (auto &v : g[u]) {
				if (!vis[v]) {
					dfs(v);
				}
				dp[u] = max(dp[u], dp[v] + 1);
			}
		};
		int ans = 0;
		for (int i = 0; i < n; ++i) {
			if (!vis[i]) {
				dfs(i);
			}
			ans = max(ans, dp[i] + 1);
		}
		return ans;
	}
};