class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        int n = pairs.size();
        unordered_map<int, int> indegree, outdegree;
        unordered_map<int, vector<int>> g;
        for (auto& p : pairs) {
            g[p[0]].push_back(p[1]);
            indegree[p[1]]++;
            outdegree[p[0]]++;
        }
        int start = g.begin()->first;
        for (auto& p : pairs) {
            if (outdegree[p[0]] - indegree[p[0]] == 1) {
                start = p[0];
                break;
            }
        }
        vector<vector<int>> ans;
        dfs(g, ans, start);
        reverse(ans.begin(), ans.end());
        return ans;
    }

    void dfs(unordered_map<int, vector<int>>& g, vector<vector<int>>& ans, int u) {
        auto& next = g[u];
        while (!next.empty()) {
            int v = next.back();
            next.pop_back();
            dfs(g, ans, v);
            ans.push_back({u, v});
        }
    }
};