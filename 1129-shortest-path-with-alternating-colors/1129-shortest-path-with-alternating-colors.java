class Pair {
    int x, y;
    Pair(int _x, int _y) {
        this.x = _x;
        this.y = _y;
    }
}

class Solution {
    public int[] shortestAlternatingPaths(int n, int[][] redEdges, int[][] blueEdges) {
        int[] ans = new int[n];
        int[][] distance = new int[n][2];
        for (int i=0; i<n; ++i) Arrays.fill(distance[i], Integer.MAX_VALUE);
        distance[0][0] = distance[0][1] = 0;
        ArrayList<ArrayList<Pair>> g = new ArrayList<>();
        for (int i=0; i<n; ++i) g.add(new ArrayList<Pair>());
        for (int i=0; i<redEdges.length; ++i) {
            g.get(redEdges[i][0]).add(new Pair(redEdges[i][1], 0));
        }
        for (int i=0; i<blueEdges.length; ++i) {
            g.get(blueEdges[i][0]).add(new Pair(blueEdges[i][1], 1));
        }
        Queue<Pair> q = new LinkedList<>();
        q.add(new Pair(0, 0)); q.add(new Pair(0, 1));
        while (!q.isEmpty()) {
            Pair node = q.peek(); q.poll();
            int prev = node.y, u = node.x;
            for (Pair next: g.get(u)) {
                if (next.y == 1 - prev) {
                    if (distance[next.x][next.y] == Integer.MAX_VALUE) {
                        distance[next.x][next.y] = 1 + distance[u][prev];
                        q.add(next);
                    }
                }
            }
        }
        for (int i=0; i<n; ++i) {
            ans[i] = Math.min(distance[i][0], distance[i][1]);
            if (ans[i] == Integer.MAX_VALUE) ans[i] = -1;
        }
        return ans;
    }
}