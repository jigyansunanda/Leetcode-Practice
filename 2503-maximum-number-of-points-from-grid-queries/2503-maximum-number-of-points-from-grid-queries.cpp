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
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int m = grid.size(), n = grid[0].size();
        vector<pair<int, int>> v;
        for (int i = 0; i < queries.size(); ++i) v.push_back({queries[i], i});
        sort(v.begin(), v.end());
        DSU dsu(m * n);
        vector<vector<int>> nodes;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                nodes.push_back({grid[i][j], i, j});
            }
        }
        sort(nodes.begin(), nodes.end());
        vector<int> ans(queries.size());
        vector<bool> vis(m * n, false);
        int index = 0;
        for (auto &e : v) {
            int q = e.first, queryIndex = e.second;
            while (index < (m * n) and nodes[index][0] < q) {
                int x = nodes[index][1];
                int y = nodes[index][2];
                int nodeIndex = (x * n) + y;
                vis[nodeIndex] = true;
                for (int dir = 0; dir < 4; ++dir) {
                    int r = x + dx[dir];
                    int c = y + dy[dir];
                    if (r >= 0 and c >= 0 and r < m and c < n and vis[(r * n) + c]) {
                        dsu.merge(nodeIndex, (r * n) + c);
                    }
                }
                index++;
            }
            if (vis[0]) ans[queryIndex] = dsu.Rank[dsu.find(0)];
        }
        return ans;
    }
};