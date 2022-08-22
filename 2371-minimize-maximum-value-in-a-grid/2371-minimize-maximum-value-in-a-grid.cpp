class Solution {
public:
	vector<vector<int>> minScore(vector<vector<int>> &grid) {
		int m = grid.size(), n = grid[0].size();
		vector<array<int, 3>> v;
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				v.push_back({grid[i][j], i, j});
			}
		}
		sort(v.begin(), v.end());
		vector<int> row(m, 0), col(n, 0);
		for (auto &[val, r, c] : v) {
			grid[r][c] = max(row[r], col[c]) + 1;
			row[r] = col[c] = grid[r][c];
		}
		return grid;
	}
};