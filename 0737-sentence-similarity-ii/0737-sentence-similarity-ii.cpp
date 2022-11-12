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
    bool areSentencesSimilarTwo(vector<string>& s1, vector<string>& s2, vector<vector<string>>& sp) {
        if (s1.size() != s2.size()) return false;
        int index = 0;
        map<string, int> mp;
        DSU dsu(4001);
        for (auto &s : sp) {
            if (mp.find(s[0]) == mp.end()) mp[s[0]] = index++;
            if (mp.find(s[1]) == mp.end()) mp[s[1]] = index++;
            dsu.merge(mp[s[0]], mp[s[1]]);
        }
        for (int i = 0; i < s1.size(); ++i) {
            if (s1[i] == s2[i]) continue;
            if (mp.find(s1[i]) == mp.end() or mp.find(s2[i]) == mp.end()) return false;
            int a = mp[s1[i]];
            int b = mp[s2[i]];
            if (dsu.find(a) != dsu.find(b)) return false;
        }
        return true;
    }
};