class TimeMap {
    unordered_map<string, vector<pair<int, string>>> mp;
public:
    TimeMap() {}

    void set(string key, string value, int timestamp) {
        mp[key].emplace_back(timestamp, value);
    }

    string get(string key, int timestamp) {
        auto &v = mp[key];
        int lo = -1, hi = v.size();
        while (hi > lo + 1) {
            int mid = (lo + hi) >> 1;
            if (v[mid].first <= timestamp) lo = mid;
            else hi = mid;
        }
        if (lo == -1) return "";
        return v[lo].second;
    }
};