class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> mp = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        int n = s.size();
        int ans = 0;
        for (int i = 0; i < n;) {
            if (i + 1 < n) {
                if (mp[s[i]] < mp[s[i + 1]]) {
                    ans += mp[s[i + 1]] - mp[s[i]];
                    i += 2;
                } else {
                    ans += mp[s[i]];
                    i += 1;
                }
            } else {
                ans += mp[s[i]];
                i += 1;
            }
        }
        return ans;
    }
};