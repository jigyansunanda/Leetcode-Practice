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
private:
    void custom_sort(vector<vector<int>>& edges) { // brings type-3 edges to front in linear time
        int index = 0, n = edges.size(), curr = 0;
        while (index < n) {
            if (edges[index][0] == 3) {
                swap(edges[index], edges[curr]);
                ++index;
                ++curr;
            } else ++index;
        }
    }
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        custom_sort(edges);
        DSU bob(n), alice(n);
        int edgesAdded = 0;
        for (auto &e : edges) {
            if (e[0] == 3) {
                bool ok1 = alice.merge(e[1] - 1, e[2] - 1);
                bool ok2 = bob.merge(e[1] - 1, e[2] - 1);
                if (ok1 or ok2) edgesAdded++;
            } else if (e[0] == 1) {
                if (alice.merge(e[1] - 1, e[2] - 1)) edgesAdded++;
            } else {
                if (bob.merge(e[1] - 1, e[2] - 1)) edgesAdded++;
            }
        }
        if (alice.components == 1 and bob.components == 1) return edges.size() - edgesAdded;
        else return -1;
    }
};