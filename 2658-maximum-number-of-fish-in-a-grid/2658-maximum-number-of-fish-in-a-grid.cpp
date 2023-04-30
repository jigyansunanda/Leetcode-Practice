class Solution {
public:
    int m, n, ans, count;
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    
    bool is_valid(int x, int y) {
        return (x >= 0 and y >= 0 and x < m and y < n);
    }
    
    int findMaxFish(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        ans = count = 0;
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (grid[i][j]) {
                    count = 0;
                    dfs(grid, i, j);
                    ans = max(ans, count);
                }
            }
        }
        return ans;
    }
    
    void dfs(vector<vector<int>>& grid, int r, int c) {
        count += grid[r][c];
        grid[r][c] = 0;
        for (int i=0; i<4; ++i) {
            int x = r + dx[i], y = c + dy[i];
            if (is_valid(x, y) and grid[x][y]) {
                dfs(grid, x, y);
            }
        }
    }
};