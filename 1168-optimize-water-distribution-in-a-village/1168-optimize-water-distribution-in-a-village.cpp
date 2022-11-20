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
    int minCostToSupplyWater(int n, vector<int>& wells, vector<vector<int>>& pipes) {
        DSU dsu(n + 1);
        for (int i = 1; i <= n; i++) {
            pipes.push_back({0, i, wells[i - 1]});
        }
        sort(pipes.begin(), pipes.end(), [&](const auto & A, const auto & B) {return A[2] < B[2];});
        int minCost = 0;
        for (int i = 0; i < pipes.size(); i++) {
            int a = pipes[i][0];
            int b = pipes[i][1];
            int c = pipes[i][2];
            minCost += (dsu.merge(a, b)) ? c : 0;
        }
        return minCost;
    }
};