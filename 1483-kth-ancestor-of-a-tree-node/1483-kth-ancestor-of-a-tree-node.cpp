class TreeAncestor {
private:
	int LOG, timer;
	vector<vector<int>> tree, dp;
	vector<int> tin, tout;

	void dfs(int u, int p) {
		tin[u] = ++timer;
		dp[0][u] = p;
		for (int i = 1; i <= LOG; ++i) {
			if (dp[i - 1][u] != -1) {
				dp[i][u] = dp[i - 1][dp[i - 1][u]];
			}
		}
		for (auto &v : tree[u]) {
			if (v != p) {
				dfs(v, u);
			}
		}
		tout[u] = ++timer;
	}

	bool is_ancestor(int u, int v) {
		return (tin[u] <= tin[v] and tout[u] >= tout[v]);
	}

public:
	TreeAncestor(int n, vector<int>& parent) {
		tin.resize(n, 0);
		tout.resize(n, 0);
		LOG = (int)(log2(n)) + 2;
		timer = 0;
		tree.resize(n);
		for (int i = 1; i < n; ++i) {
			tree[parent[i]].push_back(i);
			tree[i].push_back(parent[i]);
		}
		dp.resize(LOG + 1, vector<int>(n, -1));
		dfs(0, -1);
	}

	int getKthAncestor(int node, int k) {
		for (int index = LOG; index >= 0; --index) {
			if (k >= (1 << index) and dp[index][node] != -1) {
				k -= (1 << index);
				node = dp[index][node];
			}
		}
		return (k) ? -1 : node;
	}
};