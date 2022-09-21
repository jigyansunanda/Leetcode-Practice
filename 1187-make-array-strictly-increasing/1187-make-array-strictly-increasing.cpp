class Solution {
public:
    int dp[2001][2001][2];

    int makeArrayIncreasing(vector<int>& A, vector<int>& B) {
        sort(B.begin(), B.end());
        memset(dp, -1, sizeof dp);
        int ops = solve(A, B, 0, 0, 1);
        return (ops == INT_MAX) ? -1 : ops;
    }

    int solve(vector<int> &A, vector<int>& B, int p, int q, int fromA) {
        if (p >= A.size()) return 0;
        if (dp[p][q][fromA] != -1) return dp[p][q][fromA];
        int prev = (fromA) ? ((p == 0) ? INT_MIN : A[p - 1]) : B[q];
        dp[p][q][fromA] = INT_MAX;
        if (prev < A[p]) dp[p][q][fromA] = min(dp[p][q][fromA], solve(A, B, p + 1, q, 1));
        int next = upper_bound(B.begin() + q, B.end(), prev) - B.begin();
        if (next < B.size()) {
            int ops = solve(A, B, p + 1, next, 0);
            if (ops != INT_MAX) ops++;
            dp[p][q][fromA] = min(dp[p][q][fromA], ops);
        }
        return dp[p][q][fromA];
    }
};