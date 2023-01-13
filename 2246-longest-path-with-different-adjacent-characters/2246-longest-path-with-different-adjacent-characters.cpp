class Solution {
public:
    int longestPath(vector<int>& parent, string s) {
        int n = parent.size(), ans = 0;
        vector<int> tree[n];
        for (int i = 1; i <= n - 1; ++i) tree[parent[i]].push_back(i);
        auto dfs = [&](auto && dfs, int u, int p) -> int {
            if (tree[u].size() == 0) {
                ans = max(ans, 1);
                return 1;
            }
            vector<int> children;
            for (int v : tree[u]) {
                if (v != p) {
                    int k = dfs(dfs, v, u);
                    if (s[u] != s[v]) children.push_back(k);
                }
            }
            sort(children.begin(), children.end());
            int curr = 1;
            if (children.empty() == false) {
                curr = 1 + children.back();
                ans = max(ans, curr);
                children.pop_back();  
            } 
            if (children.size() > 0) ans = max(ans, curr + children.back());
            return curr;
        };
        ans = 0;
        dfs(dfs, 0, -1);
        return ans;
    }
};