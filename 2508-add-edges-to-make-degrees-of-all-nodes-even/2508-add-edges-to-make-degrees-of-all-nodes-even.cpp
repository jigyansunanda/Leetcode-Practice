class Solution {
public:
    bool isPossible(int n, vector<vector<int>>& edges) {
        vector<int> degree(n + 1, 0);
        unordered_set<int> g[n + 1];
        for (auto &e : edges) {
            g[e[0]].insert(e[1]);
            g[e[1]].insert(e[0]);
            degree[e[0]]++; degree[e[1]]++;
        }
        vector<int> odds;
        for (int i = 1; i <= n; ++i) {
            if (degree[i] & 1) odds.push_back(i);
        }
        int z = odds.size();
        if (z > 4 or z % 2 == 1) return false;
        else if (z == 0) return true;
        else if (z == 2) {
            int a = odds[0], b = odds[1];
            if (g[a].find(b) == g[a].end()) {
                return true;
            } else {
                for (int i = 1; i <= n; ++i) {
                    if (i == a or i == b) continue;
                    if (g[i].find(a) == g[i].end() and g[i].find(b) == g[i].end()) return true;
                }
                return false;
            }
        } else {
            int a = odds[0], b = odds[1], c = odds[2], d = odds[3];
            if (g[b].find(a) == g[b].end() and g[c].find(d) == g[c].end()) return true;
            if (g[c].find(a) == g[c].end() and g[d].find(b) == g[d].end()) return true;
            if (g[d].find(a) == g[d].end() and g[c].find(b) == g[c].end()) return true;
            return false;
        }
    }
};