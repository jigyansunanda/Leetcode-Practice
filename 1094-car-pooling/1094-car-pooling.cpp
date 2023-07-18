class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<pair<int, int>> v;
        for (auto& trip : trips) {
            v.emplace_back(trip[1], trip[0]);
            v.emplace_back(trip[2], -trip[0]);
        }
        sort(v.begin(), v.end());
        int curr = 0;
        for (auto e : v) {
            curr += e.second;
            if (curr > capacity) return false;
        }
        return true;
    }
};