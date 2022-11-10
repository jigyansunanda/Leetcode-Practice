struct DSU {
public:
    int components;
    vector<int> Parent, Rank;

    DSU(int n) : components(n), Parent(n), Rank(n, 1) { iota(Parent.begin(), Parent.end(), 0); }

    int find(int x) {
        while (x != Parent[x]) x = Parent[x] = Parent[Parent[x]];
        return x;
    }

    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return false;
        if (Rank[x] > Rank[y]) swap(x, y);
        Parent[x] = y;
        Rank[y] += Rank[x];
        --components;
        return true;
    }
};

class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n + 1, 0);
        int twoParentEdgeIndex = -1, cycleEdgeIndex = -1;
        for (int i = 0; i < (int)edges.size(); ++i) {
            int u = edges[i][0], v = edges[i][1];
            if (parent[v] == 0) parent[v] = u;
            else {
                twoParentEdgeIndex = i;
                break;
            }
        }
        DSU dsu(n + 1);
        for (int i = 0; i < (int)edges.size(); ++i) {
            if (i == twoParentEdgeIndex) continue;	// MOST IMPORTANT LINE
            int u = edges[i][0], v = edges[i][1];
            if (dsu.merge(u, v) == false) {
                cycleEdgeIndex = i;
                break;
            }
        }
        if (twoParentEdgeIndex == -1) {
            return edges[cycleEdgeIndex];
        } else {
            if (cycleEdgeIndex != -1) {
                int v = edges[twoParentEdgeIndex][1];
                int u = parent[v];
                return {u, v};
            } else {
                return edges[twoParentEdgeIndex];
            }
        }
    }
};
