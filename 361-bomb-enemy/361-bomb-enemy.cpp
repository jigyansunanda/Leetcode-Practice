class Solution {
public:
	int maxKilledEnemies(vector<vector<char>>& grid) {
		int m = grid.size(), n = grid[0].size();
		vector<vector<int>> dp1(m, vector<int>(n, 0));
		vector<vector<int>> dp2(m, vector<int>(n, 0));
		for (int row = 0; row < m; ++row) {
			int curr = 0;
			for (int col = 0; col < n; ++col) {
				if (grid[row][col] == 'W') {
					curr = 0;
				} else if (grid[row][col] == '0') {
					dp1[row][col] = curr;
				} else {
					dp1[row][col] = ++curr;
				}
			}
			curr = 0;
			for (int col = n - 1; col >= 0; --col) {
				if (grid[row][col] == 'W') {
					curr = 0;
				} else {
					curr = max(curr, dp1[row][col]);
					dp1[row][col] = curr;
				}
			}
		}
		for (int col = 0; col < n; ++col) {
			int curr = 0;
			for (int row = 0; row < m; ++row) {
				if (grid[row][col] == 'W') {
					curr = 0;
				} else if (grid[row][col] == '0') {
					dp2[row][col] = curr;
				} else {
					dp2[row][col] = ++curr;
				}
			}
			curr = 0;
			for (int row = m - 1; row >= 0; --row) {
				if (grid[row][col] == 'W') {
					curr = 0;
				} else {
					curr = max(curr, dp2[row][col]);
					dp2[row][col] = curr;
				}
			}
		}
		int ans = 0;
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (grid[i][j] == '0') {
					ans = max(ans, dp1[i][j] + dp2[i][j]);
				}
			}
		}
		return ans;
	}
};