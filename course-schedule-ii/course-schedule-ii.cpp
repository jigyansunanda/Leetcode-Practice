class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre, int courses = 0) {
        vector<int> g[n];
        vector<int> in(n, 0);
        for (auto &e : pre) {g[e[1]].push_back(e[0]); in[e[0]]++;}
        queue<int> q;
        for (int i = 0; i < n; ++i) if (!in[i]) q.push(i);
        vector<int> v;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            v.push_back(u);
            ++courses;
            for (int v : g[u]) {
                if (--in[v] == 0) q.push(v);
            }
        }
        return ((courses == n) ? v : vector<int> {});
    }
};