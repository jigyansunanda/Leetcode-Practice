class Solution {
    int m, n;
    boolean onBoundary = false;
    int subans = 0;
    int[] dx = {1, -1, 0, 0};
    int[] dy = {0, 0, 1, -1};

    public boolean isValid(int x, int y) {
        return (x >= 0 && y >= 0 && x < m && y < n);
    }

    public int numEnclaves(int[][] grid) {
        this.m = grid.length;
        this.n = grid[0].length;
        int ans = 0;
        int[][] vis = new int[m][n];
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1 && vis[i][j] == 0) {
                    onBoundary = false;
                    subans = 0;
                    dfs(grid, i, j, vis);
                    if (!onBoundary) ans += subans;
                }
            }
        }
        return ans;
    }

    public void dfs(int[][] A, int r, int c, int[][] vis) {
        vis[r][c] = 1;
        ++subans;
        onBoundary = onBoundary || (r == 0 || c == 0 || r == (m-1) || c == (n-1));
        for (int dir = 0; dir < 4; ++dir) {
            int x = r + dx[dir];
            int y = c + dy[dir];
            if (isValid(x, y)) {
                if (A[x][y] == 1 && vis[x][y] == 0) {
                    dfs(A, x, y, vis);
                }
            }
        }
    }
}