class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        vector<bool> vis(arr.size(), false);
        function<bool(int)> dfs = [&](int src) {
            if (src < 0 or src >= arr.size()) return false;
            if (vis[src]) return false;
            vis[src] = true;
            return (arr[src] == 0 or dfs(src + arr[src]) or dfs(src - arr[src]));
        };
        return dfs(start);
    }
};