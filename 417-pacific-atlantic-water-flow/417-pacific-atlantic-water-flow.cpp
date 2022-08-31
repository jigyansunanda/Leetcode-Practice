class Solution {
public:
	int dx[4] = {1, -1, 0, 0};
	int dy[4] = {0, 0, -1, 1};

	vector<vector<int>> ans;
	vector<vector<int>> mask;

	vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
		int m = heights.size(), n = heights[0].size();
		mask.resize(m, vector<int>(n, 0));

		function<void(int, int, int, int)> dfs = [&](int r, int c, int prev, int val) {
			if (r < 0 or c < 0 or r >= m or c >= n or ((mask[r][c] | val) == mask[r][c])) return;
			if (heights[r][c] < prev) return;
			mask[r][c] |= val;
			if (mask[r][c] == 3) ans.push_back({r, c});
			for (int dir = 0; dir < 4; ++dir) {
				int x = r + dx[dir];
				int y = c + dy[dir];
				dfs(x, y, heights[r][c], mask[r][c]);
			}
		};

		for (int i = 0; i < m; ++i) {
			dfs(i, 0, INT_MIN, 1);
			dfs(i, n - 1, INT_MIN, 2);
		}
		for (int j = 0; j < n; ++j) {
			dfs(0, j, INT_MIN, 1);
			dfs(m - 1, j, INT_MIN, 2);
		}
		return ans;
	}
};