class Solution {
    int m, n;
    final int[] dx = {1, -1, 0, 0};
    final int[] dy = {0, 0, 1, -1};

    private boolean isValid(int r, int c) {
        return (r >= 0 && r < m && c < n && c >= 0);
    }

    public int shortestPath(int[][] grid, int k) {
        this.m = grid.length;
        this.n = grid[0].length;
        Queue<int[]> queue = new LinkedList<>();
        int[][] vis = new int[m][n];
        for (int i = 0; i < vis.length; i++) {
            Arrays.fill(vis[i], -1);
        }
        queue.add(new int[] {0, 0, k, 0});
        while (!queue.isEmpty()) {
            int x = queue.peek()[0], y = queue.peek()[1];
            int k_left = queue.peek()[2], pathLength = queue.peek()[3];
            queue.poll();
            if (x == m - 1 && y == n - 1) return pathLength;
            for (int dir = 0; dir < 4; dir++) {
                int r = x + dx[dir];
                int c = y + dy[dir];
                if (!isValid(r, c)) continue;
                int k_new = k_left - (grid[r][c] == 1 ? 1 : 0);
                if (k_new < 0 || vis[r][c] >= k_new) continue;
                vis[r][c] = k_new;
                queue.add(new int[] {r, c, k_new, pathLength + 1});
            }
        }
        return -1;
    }
}