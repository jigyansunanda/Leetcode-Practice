class DSU {
    int n, components;
    int[] parent;
    int[] rank;
    DSU(int n) {
        this.n = n;
        this.components = n;
        this.rank = new int[n];
        this.parent = new int[n];
        for (int i = 0; i < n; ++i) parent[i] = i;
    }
    public int find(int x) {
        while (x != parent[x]) x = parent[x] = parent[parent[x]];
        return x;
    }
    public boolean merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return false;
        if (rank[x] > rank[y]) {int z = y; y = x; x = z;}
        parent[x] = y;
        rank[y] += rank[x];
        --components;
        return true;
    }
    public int get_components() { return this.components; }
    public boolean is_same_component(int x, int y) {return (find(x) == find(y));}
}

class Solution {
    public int earliestAcq(int[][] logs, int n) {
        Arrays.sort(logs, (log1, log2) -> log1[0] - log2[0]);
        DSU dsu = new DSU(n);
        int ans = 0;
        for (int i = 0; i < logs.length; ++i) {
            if (dsu.merge(logs[i][1], logs[i][2])) {
                ans = Math.max(ans, logs[i][0]);
            }
        }
        return ((dsu.get_components() == 1) ? ans : -1);
    }
}