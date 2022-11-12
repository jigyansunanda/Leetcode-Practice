class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        unordered_set<string> st(wordDict.begin(), wordDict.end());
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                string tmp = s.substr(j, i - j);
                if (st.find(tmp) != st.end() and dp[j]) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};