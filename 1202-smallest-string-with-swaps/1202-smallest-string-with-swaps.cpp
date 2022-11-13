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
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.size();
        DSU dsu(n);
        for (auto &p : pairs) dsu.merge(p[0], p[1]);
        unordered_map<int, vector<char>> mp;
        for (int i = 0; i < n; ++i) {
            int p = dsu.find(i);
            mp[p].push_back(s[i]);
        }
        for (auto &p : mp) sort(p.second.begin(), p.second.end(), greater<char>());
        for (int i = 0; i < n; ++i) {
            int p = dsu.find(i);
            s[i] = mp[p].back();
            mp[p].pop_back();
        }
        return s;
    }
};