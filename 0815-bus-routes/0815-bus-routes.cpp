class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        unordered_map<int, vector<int>> g;
        for (int i = 0; i < routes.size(); ++i) {
            for (auto &j : routes[i]) {
                g[j].push_back(i);
            }
        }
        queue<pair<int, int>> q;
        q.push({source, 0});
        unordered_set<int> vis = {source};
        while (!q.empty()) {
            int node = q.front().first, distance = q.front().second;
            q.pop();
            if (node == target) return distance;
            for (int route : g[node]) {
                for (int &stops : routes[route]) {
                    if (vis.find(stops) == vis.end()) {
                        q.push({stops, distance + 1});
                        vis.insert(stops);
                    }
                }
                routes[route].clear();
            }
        }
        return -1;
    }
};