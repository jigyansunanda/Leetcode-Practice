class Solution {
    private int n;
    private int[][] graph;
    private List<List<Integer>> paths;

    public List<List<Integer>> allPathsSourceTarget(int[][] graph) {
        this.graph = graph;
        this.n = graph.length;
        this.paths = new ArrayList<>();
        List<Integer> path = new ArrayList<>();
        boolean[] vis = new boolean[n];
        getAllPaths(0, path, vis);
        return paths;
    }

    private void getAllPaths(int node, List<Integer> path, boolean[] vis) {
        vis[node] = true;
        path.add(node);
        if (node == n - 1) {
            paths.add(new ArrayList<>(path));
        } else {
            for (int next : graph[node]) {
                if (vis[next]) continue;
                getAllPaths(next, path, vis);
            }
        }
        vis[node] = false;
        path.remove(path.size() - 1);
    }
}