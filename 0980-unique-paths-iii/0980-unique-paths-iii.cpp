class Solution {
public:
    int m, n, cnt;
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    int uniquePathsIII(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size(), cnt = 0;
        int start_x = -1, start_y = -1;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    start_x = i, start_y = j;
                }
                cnt += (grid[i][j] == 0);
            }
        }
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        return dfs(grid, start_x, start_y, 0, vis);
    }

    int dfs(vector<vector<int>>& grid, int r, int c, int num, vector<vector<bool>>& vis) {
        if (grid[r][c] == 2) {
            return (num == cnt) ? 1 : 0;
        }
        vis[r][c] = true;
        int ans = 0;
        for (int dir = 0; dir < 4; ++dir) {
            int x = r + dx[dir];
            int y = c + dy[dir];
            if (isValid(x, y) and !vis[x][y] and grid[x][y] != -1) {
                ans += dfs(grid, x, y, num + (grid[x][y] == 0), vis);
            }
        }
        vis[r][c] = false;
        return ans;
    }

    bool isValid(int x, int y) {
        return (x >= 0 and y >= 0 and x < m and y < n);
    }
};