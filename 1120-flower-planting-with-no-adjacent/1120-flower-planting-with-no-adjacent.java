class Graph {
    int n;
    ArrayList<ArrayList<Integer>> edges;

    Graph(int n) {
        this.n = n;
        this.edges = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            edges.add(new ArrayList<>());
        }
    }

    public void addEdge(int u, int v) {
        edges.get(u).add(v);
        edges.get(v).add(u);
    }

    public ArrayList<ArrayList<Integer>> getConnectedComponents() {
        ArrayList<ArrayList<Integer>> components = new ArrayList<>();
        boolean[] vis = new boolean[n];
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                ArrayList<Integer> component = new ArrayList<>();
                dfs(i, vis, component);
                components.add(component);
            }
        }
        return components;
    }

    private void dfs(int node, boolean[] vis, ArrayList<Integer> component) {
        vis[node] = true;
        component.add(node);
        for (int next : edges.get(node)) {
            if (!vis[next]) {
                dfs(next, vis, component);
            }
        }
    }

    public boolean canColor(int node, int color, int[] colors) {
        colors[node] = color;
        for (int next : edges.get(node)) {
            if (colors[next] == color) return false;
            if (colors[next] != -1) continue;
            boolean isPossible = false;
            for (int c = 1; c <= 4; ++c) {
                if (c == color) continue;
                boolean canBeColored = canColor(next, c, colors);
                if (canBeColored) {
                    isPossible = true;
                    break;
                }
            }
            if (!isPossible) {
                colors[node] = -1;
                return false;
            }
        }
        return true;
    }
}

class Solution {
    public int[] gardenNoAdj(int n, int[][] paths) {
        Graph graph = new Graph(n);
        for (int i = 0; i < paths.length; i++) {
            graph.addEdge(paths[i][0] - 1, paths[i][1] - 1);
        }
        ArrayList<ArrayList<Integer>> components = graph.getConnectedComponents();
        int[] colors = new int[n];
        Arrays.fill(colors, -1);
        for (ArrayList<Integer> component : components) {
            for (int color = 1; color < 5; ++color) {
                int node = component.get(0);
                if (graph.canColor(node, color, colors)) {
                    break;
                }
            }
        }
        return colors;
    }
}