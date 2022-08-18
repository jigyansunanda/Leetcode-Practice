class Solution {
public:
    string minWindow(string s, string t) {
        if (s.size() < t.size()) return "";
        vector<int> T(128, 0), S(128, 0);
        for (auto c : t) T[c]++;
        int l = 0;
        int minWindowSize = INT_MAX, start = -1;
        function<bool()> ok = [&]() {
            for (int i = 0; i < 128; ++i) {
                if (S[i] < T[i]) return false;
            }
            return true;
        };
        for (int r = 0; r < s.size(); ++r) {
            S[s[r]]++;
            while (ok()) {
                if (minWindowSize > r - l + 1) {
                    minWindowSize = r - l + 1;
                    start = l;
                }
                S[s[l]]--;
                l++;
            }
        }
        return (minWindowSize == INT_MAX) ? "" : s.substr(start, minWindowSize);
    }
};