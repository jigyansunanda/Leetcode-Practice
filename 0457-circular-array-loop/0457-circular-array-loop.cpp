class Solution {
private:
    bool dfs(vector<int>* g, int u, vector<bool>& vis, vector<bool>& rec) {
        vis[u] = true;
        rec[u] = true;
        for (int v : g[u]) {
            if (vis[v]) {
                if (rec[v]) return true;
            } else {
                bool isCycle = dfs(g, v, vis, rec);
                if (isCycle) return true;
            }
        }
        rec[u] = false;
        return false;
    }

public:
    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();
        vector<int> g[n];
        for (int i = 0; i < n; ++i) {
            int j = (i + nums[i]) % n;
            if (j < 0) j += n;
            if (nums[i] / abs(nums[i]) == nums[j] / abs(nums[j]) and i != j) {
                g[i].push_back(j);
            }
        }
        vector<bool> vis(n, false);
        vector<bool> rec(n, false);
        for (int i = 0; i < n; ++i) {
            if (vis[i] == false) {
                bool isCycle = dfs(g, i, vis, rec);
                if (isCycle) return true;
            }
        }
        return false;
    }
};