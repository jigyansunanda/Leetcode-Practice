class Solution {
public:
    int getMaximumGold(vector<vector<int>>& grid, int ans = 0) {
        int m = grid.size(), n = grid[0].size();
        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, -1, 1};

        function<int(int, int, vector<vector<bool>>&)> dfs = [&](int r, int c, vector<vector<bool>>& vis) {
            vis[r][c] = true;
            int total = grid[r][c];
            int maxFromChild = 0;
            for (int i = 0; i < 4; ++i) {
                int x = r + dx[i], y = c + dy[i];
                if (x >= 0 and y >= 0 and x < m and y < n) {
                    if (!vis[x][y] and grid[x][y]) {
                        maxFromChild = max(dfs(x, y, vis), maxFromChild);
                    }
                }
            }
            vis[r][c] = false;
            return total + maxFromChild;
        };

        vector vis(m, vector<bool>(n, false));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j]) {
                    int subans = dfs(i, j, vis);
                    ans = max(ans, subans);
                }
            }
        }
        return ans;
    }
};