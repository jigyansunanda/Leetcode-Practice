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
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        int q = queries.size();
        for (int i = 0; i < q; ++i) queries[i].push_back(i);
        sort(edgeList.begin(), edgeList.end(), [&](const auto & A, const auto & B) {return (A[2] < B[2]);});
        sort(queries.begin(), queries.end(), [&](const auto & A, const auto & B) {return (A[2] < B[2]);});
        DSU dsu(n);
        vector<bool> ans(q);
        int index = 0;
        for (auto &query : queries) {
            while (index < edgeList.size() and edgeList[index][2] < query[2]) {
                dsu.merge(edgeList[index][0], edgeList[index][1]);
                ++index;
            }
            ans[query[3]] = (dsu.find(query[0]) == dsu.find(query[1]));
        }
        return ans;
    }
};