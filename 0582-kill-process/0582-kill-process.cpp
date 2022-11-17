class Solution {
public:
    int root;
    vector<int> ans;

    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        int n = pid.size();
        int maxn = 5e4 + 1;
        vector<int> tree[maxn];
        for (int i = 0; i < n; ++i) {
            if (ppid[i] == 0) root = pid[i];
            else tree[ppid[i]].push_back(pid[i]);
        }
        ans.clear();
        dfs(tree, root, kill, false);
        return ans;
    }

    void dfs(vector<int> *tree, int u, int kill, bool isInSubtree) {
        isInSubtree |= (u == kill);
        if (isInSubtree) ans.push_back(u);
        for (int &v : tree[u]) {
            dfs(tree, v, kill, isInSubtree || (v == kill));
        }
        if (u == kill) isInSubtree = false;
        return;
    }
};