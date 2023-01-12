class Solution {
public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>> count(n, vector<int>(26, 0));
        vector<int> tree[n];
        for (auto &e : edges) {
            tree[e[0]].push_back(e[1]);
            tree[e[1]].push_back(e[0]);
        }

        auto dfs = [&] (auto && dfs, int u, int p) -> void {
            count[u][labels[u] - 'a']++;
            for (auto v : tree[u]) {
                if (v != p) {
                    dfs(dfs, v, u);
                    for (int i = 0; i < 26; ++i) {
                        count[u][i] += count[v][i];
                    }
                }
            }
        };

        dfs(dfs, 0, -1);
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            ans.push_back(count[i][labels[i] - 'a']);
        }
        return ans;
    }
};
