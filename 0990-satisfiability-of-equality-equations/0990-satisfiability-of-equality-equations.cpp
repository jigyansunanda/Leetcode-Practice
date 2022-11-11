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
    bool equationsPossible(vector<string>& equations) {
        DSU dsu(26);
        for (auto &e : equations) {
            if (e[1] == '=') dsu.merge(e[0] - 'a', e[3] - 'a');
        }
        for (auto &e : equations) {
            if (e[1] == '!') {
                int a = e[0] - 'a';
                int b = e[3] - 'a';
                if (dsu.find(a) == dsu.find(b)) return false;
            }
        }
        return true;
    }
};