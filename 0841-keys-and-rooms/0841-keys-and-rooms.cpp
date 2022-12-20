class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> vis(n, false);
        auto dfs = [&](int u, auto && dfs) -> void {
            vis[u] = true;
            for (int &v : rooms[u]) {
                if (vis[v] == false) {
                    dfs(v, dfs);
                }
            }
        };
        dfs(0, dfs);
        int visitedRooms = count_if(vis.begin(), vis.end(), [&](bool x) {return x == true;});
        return (visitedRooms == n);
    }
};