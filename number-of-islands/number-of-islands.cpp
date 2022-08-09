class Solution {
public:
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,-1,1};
    int numIslands(vector<vector<char>>& grid, int ans = 0) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> vis(m,vector<bool>(n, false));
        function<void(int,int)> dfs = [&](int r, int c) {
            vis[r][c] = true;
            for (int k=0; k<4; ++k) {
                int x = r + dx[k];
                int y = c + dy[k];
                if (x >= 0 and y >= 0 and x < m and y < n and grid[x][y] == '1' and !vis[x][y]) {
                    dfs(x, y);
                }
            }
        };
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (vis[i][j] == false and grid[i][j] == '1') {
                    dfs(i, j);
                    ++ans;
                }
            }
        }
        return ans;
    }
};