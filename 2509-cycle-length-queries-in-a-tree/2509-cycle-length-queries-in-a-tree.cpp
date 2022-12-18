class Solution {
public:
    vector<int> cycleLengthQueries(int n, vector<vector<int>>& queries) {
        vector<int> ans;
        for (auto &e : queries) {
            int a = e[0], b = e[1];
            unordered_map<int, int> mp;
            int d = 0;
            while (a >= 1) {
                mp[a] = d;
                ++d;
                a = (a) / 2;
            }
            d = 0;
            while (b >= 1) {
                if (mp.find(b) != mp.end()) {
                    // debug(b, mp[b], d);
                    ans.push_back(d + mp[b]+1);
                    break;
                } else {
                    ++d;
                    b = (b) / 2;
                }
            }

        }
        return ans;
    }
};