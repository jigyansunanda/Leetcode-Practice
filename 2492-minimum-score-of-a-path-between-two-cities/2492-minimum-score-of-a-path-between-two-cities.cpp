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
    int minScore(int n, vector<vector<int>>& roads) {
        int ans = INT_MAX;
        DSU dsu(n + 1);
        for (auto &r : roads) dsu.merge(r[0], r[1]);
        for (auto &r : roads) {
            if (dsu.find(1) == dsu.find(r[0]) or dsu.find(1) == dsu.find(r[1])) {
                ans = min(ans, r[2]);
            }
        }
        return ans;
    }
};