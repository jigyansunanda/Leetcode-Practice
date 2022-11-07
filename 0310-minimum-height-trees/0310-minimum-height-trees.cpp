class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n <= 2) {
            vector<int> ans;
            for (int i = 0; i < n; ++i) ans.push_back(i);
            return ans;
        }
        vector<int> tree[n];
        vector<int> in(n, 0);
        for (auto &e : edges) {
            tree[e[0]].push_back(e[1]);
            tree[e[1]].push_back(e[0]);
            in[e[0]]++; in[e[1]]++;
        }
        queue<int> q;
        for (int i = 0; i < n; ++i) if (in[i] == 1) q.push(i);
        int remainingNodes = n;
        while (remainingNodes > 2) {
            int z = q.size();
            while (z--) {
                int u = q.front();
                q.pop();
                --remainingNodes;
                for (int v : tree[u]) {
                    in[v]--;
                    if (in[v] == 1) q.push(v);
                }
            }
        }
        vector<int> ans;
        while (!q.empty()) {
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
};