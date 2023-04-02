class Solution {
public:
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        map<char, int> mp;
        for (int i = 0; i < ((int) chars.size()); ++i) mp[chars[i]] = vals[i];
        vector<int> A;
        for (int i = 0; i < ((int) s.size()); ++i) {
            if (mp.find(s[i]) == mp.end()) A.push_back((s[i] - 'a') + 1);
            else A.push_back(mp[s[i]]);
        }
        int ans = 0, curr = 0;
        for (int i = 0; i <= ((int) A.size()) - 1; ++i) {
            curr = max(curr + A[i], A[i]);
            ans = max(ans, curr);
        }
        return ans;
    }
};
