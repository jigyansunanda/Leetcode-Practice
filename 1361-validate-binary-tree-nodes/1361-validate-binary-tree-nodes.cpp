class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& lc, vector<int>& rc) {
        vector<int> in(n, 0);
        vector<int> g[n];
        for (int i = 0; i < n; ++i) {
            if (lc[i] != -1) {g[i].push_back(lc[i]); in[lc[i]]++;}
            if (rc[i] != -1) {g[i].push_back(rc[i]); in[rc[i]]++;}
        }
        int rootcount = count_if(in.begin(), in.end(), [](int x) {return x == 0;});
        if (rootcount > 1 or (*max_element(in.begin(), in.end()) > 1)) return false;
        int nodes = 0;
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (!in[i]) q.push(i);
        }
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            ++nodes;
            for (auto &v : g[node]) {
                if (--in[v] == 0) {
                    q.push(v);
                }
            }
        }
        return (nodes == n);
    }
};