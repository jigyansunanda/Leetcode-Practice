class Solution {
    public int longestCycle(int[] edges) {
        int n = edges.length;
        ArrayList<ArrayList<Integer>> g = new ArrayList<>();
        for (int i = 0; i < n; ++i) {
            g.add(new ArrayList<>());
        }
        for (int i = 0; i < n; ++i) {
            if (edges[i] != -1) {
                g.get(i).add(edges[i]);
            }
        }
        int longestCycle = -1;
        boolean[] vis = new boolean[n];
        boolean[] rec = new boolean[n];
        int[] par = new int[n];
        Arrays.fill(par, -1);
        for (int i = 0; i < n; ++i) {
            if (!vis[i]) {
                int cycleLength = dfs(g, i, i, par, vis, rec);
                longestCycle = Math.max(longestCycle, cycleLength);
            }
        }
        return longestCycle;
    }

    public int dfs(ArrayList<ArrayList<Integer>> g, int u, int p, int[] par, boolean[] vis, boolean[] rec) {
        int currCycleLength = -1;
        vis[u] = true;
        rec[u] = true;
        par[u] = p;
        for (int v : g.get(u)) {
            if (!vis[v]) {
                int childCycleLength = dfs(g, v, u, par, vis, rec);
                currCycleLength = Math.max(currCycleLength, childCycleLength);
            } else {
                if (rec[v]) {
                    int newCycleLength = 1;
                    int currNode = u;
                    while (v != currNode) {
                        currNode = par[currNode];
                        ++newCycleLength;
                    }
                    currCycleLength = Math.max(currCycleLength, newCycleLength);
                }
            }
        }
        rec[u] = false;
        return currCycleLength;
    }
}