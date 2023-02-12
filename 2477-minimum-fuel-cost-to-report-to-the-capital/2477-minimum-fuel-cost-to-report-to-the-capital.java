class Tree {
    int n;
    long ans, seats;
    ArrayList<ArrayList<Integer>> tree;
    Tree(int _n, int _seats) {
        this.n = _n;
        this.seats = Long.valueOf(_seats);
        this.tree = new ArrayList<>();
        this.ans = 0;
        for (int i = 0; i < n; ++i) tree.add(new ArrayList<>());
    }
    void add_edge(int u, int v) {
        tree.get(u).add(v);
        tree.get(v).add(u);
    }
    long dfs(int u, int p) {
        long count = 1;
        for (int v: tree.get(u)) {
            if (v != p) {
                count += dfs(v, u);
            }
        }
        if (u != 0) {
            ans += (count / seats);
            if (count % seats != 0) ++ans;
        }
        return count;
    }
}

class Solution {
    public long minimumFuelCost(int[][] roads, int seats) {
        int n = roads.length + 1;
        Tree t = new Tree(n, seats);
        for (int i = 0; i < roads.length; ++i) {
            t.add_edge(roads[i][0], roads[i][1]);
        }
        t.dfs(0, -1);
        return t.ans;
    }
}