class Solution {
public:
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {1, -1, 0, 0};
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size(), ans = 0;
        vector<vector<int>> dp(n, vector<int>(m, -1));
        function<void(int, int)> dfs = [&](int r, int c) {
            dp[r][c] = 1;
            for (int k = 0; k < 4; ++k) {
                int x = r + dx[k];
                int y = c + dy[k];
                if (x >= 0 and y >= 0 and x < n and y < m) {
                    if (matrix[x][y] > matrix[r][c]) {
                        if (dp[x][y] == -1) dfs(x, y);
                        dp[r][c] = max(dp[r][c], dp[x][y] + 1);
                    }
                }
            }
            ans = max(ans, dp[r][c]);
        };
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (dp[i][j] == -1) {
                    dfs(i, j);
                }
            }
        }
        return ans;
    }
};