class Solution {
    final int[] dx = {1, -1, 0, 0};
    final int[] dy = {0, 0, 1, -1};

    public int orangesRotting(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        int freshCount = 0;
        Queue<int[]> queue = new LinkedList<>();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    queue.add(new int[] {i, j});
                }
                freshCount += (grid[i][j] == 1) ? 1 : 0;
            }
        }
        int timeTaken = 0;
        while (!queue.isEmpty()) {
            if (freshCount == 0) break;
            int size = queue.size();
            while (size-- > 0) {
                int[] cell = queue.poll();
                for (int dir = 0; dir < 4; ++dir) {
                    int x = cell[0] + dx[dir];
                    int y = cell[1] + dy[dir];
                    if (x >= 0 && y >= 0 && x < m && y < n) {
                        if (grid[x][y] == 1) {
                            --freshCount;
                            grid[x][y] = 2;
                            queue.add(new int[] {x, y});
                        }
                    }
                }
            }
            ++timeTaken;
        }
        return (freshCount > 0) ? -1 : timeTaken;
    }
}