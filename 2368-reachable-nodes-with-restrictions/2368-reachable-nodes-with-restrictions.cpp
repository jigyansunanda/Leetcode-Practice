class Solution {
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        set<int> st;
        for (auto &u : restricted) st.insert(u);
        vector<int> tr[n];
        for (auto &e : edges) {
            tr[e[0]].push_back(e[1]);
            tr[e[1]].push_back(e[0]);
        }
        int ans = 0;
        function<void(int, int)> dfs = [&](int u, int p) {
            if (st.find(u) != st.end()) return;
            ++ans;
            for (auto &v : tr[u]) {
                if (v != p) {
                    dfs(v, u);
                }
            }
        };
        dfs(0, 0);
        return ans;
    }
};