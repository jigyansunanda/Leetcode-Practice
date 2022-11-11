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
    int earliestAcq(vector<vector<int>>& logs, int n) {
        DSU dsu(n);
        sort(logs.begin(), logs.end(), [&](const auto & A, const auto & B) {return A[0] < B[0];});
        for (auto &log : logs) {
            dsu.merge(log[1], log[2]);
            if (dsu.components == 1) return log[0];
        }
        return (dsu.components == 1) ? logs.back()[0] : -1;
    }
};