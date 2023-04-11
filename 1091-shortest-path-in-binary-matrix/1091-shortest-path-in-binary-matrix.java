class Pair {
    int x, y;
    Pair(int _x, int _y) {
        this.x = _x;
        this.y = _y;
    }
}

class Solution {
    int n;
    int[] dx = { 1, -1, 0, 0, 1, 1, -1, -1};
    int[] dy = { 0, 0, 1, -1, -1, 1, -1, 1 };
    
    public boolean isValid(int x, int y) {
        return (x >= 0 && y >= 0 && x < n && y < n);
    }
    
    public int shortestPathBinaryMatrix(int[][] grid) {
        this.n = grid.length;
        if (grid[0][0] == 1) return -1;
        int[][] vis = new int[n][n];
        for (int i=0; i<n; ++i) Arrays.fill(vis[i], Integer.MAX_VALUE);
        Queue<Pair> q = new LinkedList<>();
        q.add(new Pair(0, 0));
        vis[0][0] = 1;
        while (!q.isEmpty()) {
            int r = q.peek().x, c = q.peek().y;
            q.poll();
            for (int dir = 0; dir < 8; ++dir) {
                int x = r + dx[dir];
                int y = c + dy[dir];
                if (isValid(x, y)) {
                    if (grid[x][y] == 0) {
                        if (vis[x][y] == Integer.MAX_VALUE) {
                            vis[x][y] = vis[r][c] + 1;
                            q.add(new Pair(x, y));
                        }
                    }
                }
            }
        }
        
        return (vis[n-1][n-1] == Integer.MAX_VALUE) ? -1 : vis[n-1][n-1];
    }
}