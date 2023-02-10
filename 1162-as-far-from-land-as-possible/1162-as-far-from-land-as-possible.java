class Pair {
    int x, y;
    Pair(int _x, int _y) {
        this.x = _x;
        this.y = _y;
    }
}

class Solution {
    static int[] dx= {1, -1, 0, 0};
    static int[] dy = {0, 0, -1, 1};
    public int maxDistance(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        int[][] distance = new int[m][n];
        for (int i=0; i<m; ++i) Arrays.fill(distance[i], Integer.MAX_VALUE);
        Queue<Pair> q = new LinkedList<>();
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (grid[i][j] == 1) {
                    q.add(new Pair(i, j));
                    distance[i][j] = 0;
                }
            }
        }
        while (!q.isEmpty()) {
            Pair p = q.peek();
            q.poll();
            for (int i=0; i<4; ++i) {
                int r = p.x + dx[i], c = p.y + dy[i];
                if (r >= 0 && c >= 0 && r < m && c < n) {
                    if (grid[r][c] == 0 && distance[r][c] == Integer.MAX_VALUE) {
                        distance[r][c] = distance[p.x][p.y] + 1;
                        q.add(new Pair(r, c));
                    }   
                }
            }
        }
        int ans = -1;
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (grid[i][j] == 0 && distance[i][j] != Integer.MAX_VALUE) {
                    ans = Math.max(ans, distance[i][j]);
                }
            }
        }
        return ans;
    }
}