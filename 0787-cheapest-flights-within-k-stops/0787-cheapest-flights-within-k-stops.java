class Pair {
    int x, y;
    Pair(int x, int y) {
        this.x = x;
        this.y = y;
    }
    int getKey() {return x;}
    int getValue() {return y;}
}

class Solution {
    public int findCheapestPrice(int n, int[][] flights, int src, int dst, int k) {
        ArrayList<ArrayList<Pair>> graph = new ArrayList<>(n);
        for (int i = 0; i < n; ++i) graph.add(new ArrayList<Pair>());
        for (int i = 0; i < flights.length; ++i) {
            int u = flights[i][0], v = flights[i][1], w = flights[i][2];
            graph.get(u).add(new Pair(v, w));
        }
        int[][] dp = new int[n][k + 2];
        for (int i = 0; i < n; ++i) Arrays.fill(dp[i], Integer.MAX_VALUE);
        dp[src][0] = 0;
        for (int len = 1; len <= k + 1; ++len) {
            for (int i = 0; i < n; ++i) {
                if (dp[i][len - 1] != Integer.MAX_VALUE) {
                    for (Pair p : graph.get(i)) {
                        int v = p.getKey(), w = p.getValue();
                        dp[v][len] = Math.min(dp[v][len], dp[i][len - 1] + w);
                    }
                }
            }
        }
        int ans = Integer.MAX_VALUE;
        for (int len = 0; len < k + 2; ++len) ans = Math.min(ans, dp[dst][len]);
        return ans == Integer.MAX_VALUE ? -1 : ans;
    }
}