struct DSU {
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
    int makeConnected(int n, vector<vector<int>>& connections) {
        DSU dsu(n);
        int unnecessaryCables = 0;
        for (auto &e : connections) {
            if (dsu.merge(e[0], e[1]) == false) unnecessaryCables++;
        }
        if (dsu.components == 1) return 0;
        if (dsu.components - 1 <= unnecessaryCables) return dsu.components - 1;
        return -1;
    }
};