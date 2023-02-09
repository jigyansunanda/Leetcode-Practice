class Solution {
public:
    long long distinctNames(vector<string>& ideas, long long ans = 0) {
        int n = ideas.size();
        unordered_set<string> char_to_suffix[26];
        long long dp[26][26] = {};
        for (auto& idea : ideas) char_to_suffix[idea.front() - 'a'].insert(idea.substr(1));
        for (int start1 = 0; start1 < 26; ++start1) {
            for (auto& suffix : char_to_suffix[start1]) {
                for (int start2 = 0; start2 < 26; ++start2) {
                    dp[start1][start2] += (char_to_suffix[start2].count(suffix) == 0);
                }
            }
        }
        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < 26; ++j) {
                ans += (dp[i][j] * dp[j][i]);
            }
        }
        return ans;
    }
};