class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& pre, vector<vector<int>>& queries) {
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for (int i = 0; i < n; ++i) dp[i][i] = true;
        for (auto &e : pre) dp[e[0]][e[1]] = true;
        for (int mid = 0; mid < n; ++mid) {
            for (int start = 0; start < n; ++start) {
                if (dp[start][mid]) {
                    for (int end = 0; end < n; ++end) {
                        dp[start][end] = dp[start][end] or (dp[start][mid] and dp[mid][end]);
                    }
                }
            }
        }
        vector<bool> ans;
        for (auto &q : queries) ans.push_back(dp[q[0]][q[1]]);
        return ans;
    }
};