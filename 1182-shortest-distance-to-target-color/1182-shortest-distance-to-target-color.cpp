class Solution {
public:
    vector<int> shortestDistanceColor(vector<int>& colors, vector<vector<int>>& queries) {
        vector<int> g[4];
        for (int i = 0; i < (int)colors.size(); ++i) g[colors[i]].push_back(i);
        vector<int> ans;
        for (auto &q : queries) {
            int index = q[0], c = q[1];
            if (g[c].empty()) {
                ans.push_back(-1);
                continue;
            }
            int lo = -1, hi = g[c].size();
            while (hi > lo + 1) {
                int mid = (lo + hi) >> 1;
                if (g[c][mid] < index) lo = mid;
                else hi = mid;
            }
            if (lo == -1) ans.push_back(abs(g[c][hi] - index));
            else if (hi == (int) g[c].size()) ans.push_back(abs(g[c][lo] - index));
            else ans.push_back(min(abs(g[c][lo] - index), abs(g[c][hi] - index)));
        }
        return ans;
    }
};