class Solution {
    int m, n;
    boolean allFound = false;
    int[] dx = {1, -1, 0, 0};
    int[] dy = {0, 0, 1, -1};

    public boolean isValid(int x, int y) {
        return (x >= 0 && y >= 0 && x < m && y < n);
    }

    public int countSubIslands(int[][] grid1, int[][] grid2) {
        this.m = grid1.length;
        this.n = grid1[0].length;
        int ans = 0;
        int[][] vis = new int[m][n];
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid2[i][j] == 1 && vis[i][j] == 0) {
                    allFound = true;
                    dfs(grid1, grid2, i, j, vis);
                    if (allFound) ++ans;
                }
            }
        }
        return ans;
    }

    public void dfs(int[][] A, int[][] B, int r, int c, int[][] vis) {
        vis[r][c] = 1;
        allFound = allFound && (A[r][c] == 1);
        for (int dir = 0; dir < 4; ++dir) {
            int x = r + dx[dir];
            int y = c + dy[dir];
            if (isValid(x, y) && B[x][y] == 1 && vis[x][y] == 0) {
                dfs(A, B, x, y, vis);
            }
        }
    }
}