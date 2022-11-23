class Solution {
public:
    vector<int> subtreecount, subtreesum;
    int deleteTreeNodes(int n, vector<int>& parent, vector<int>& value) {
        vector<int> tree[n];
        for (int i = 1; i <= n - 1; ++i) tree[parent[i]].push_back(i);
        subtreecount.resize(n, 0);
        subtreesum.resize(n, 0);
        dfs1(tree, 0, value);
        return n - dfs2(tree, 0);
    }
    void dfs1(vector<int> *tree, int u, vector<int>& value) {
        subtreecount[u] = 1;
        subtreesum[u] = value[u];
        for (int &v : tree[u]) {
            dfs1(tree, v, value);
            subtreecount[u] += subtreecount[v];
            subtreesum[u] += subtreesum[v];
        }
    }
    int dfs2(vector<int> *tree, int u) {
        if (subtreesum[u] == 0) return subtreecount[u];
        int count = 0;
        for (int &v : tree[u]) {
            count += dfs2(tree, v);
        }
        return count;
    }
};