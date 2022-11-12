struct DSU {
public:
    int components;
    vector<int> Parent;

    DSU(int n) : components(n), Parent(n) { iota(Parent.begin(), Parent.end(), 0); }

    int find(int x) {
        while (x != Parent[x]) x = Parent[x] = Parent[Parent[x]];
        return x;
    }

    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return false;
        Parent[x] = Parent[y] = min(x, y);
        --components;
        return true;
    }
};

class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        DSU dsu(26);
        for (int i = 0; i < (int)s1.size(); ++i) {
            int a = s1[i] - 'a', b = s2[i] - 'a';
            dsu.merge(a, b);
        }
        for (auto &c : baseStr) c = (char)('a' + dsu.find(c - 'a'));
        return baseStr;
    }
};