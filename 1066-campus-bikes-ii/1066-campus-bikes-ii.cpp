class Solution {
public:
    int n, m;
    vector<vector<int>> dp;
    const int inf = INT_MAX;

    int assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        n = workers.size(), m = bikes.size();
        int mask = (1 << n) - 1;
        dp.resize(mask + 1, vector<int>(m, -1));
        return solve(workers, bikes, mask, 0);
    }

    int solve(vector<vector<int>>& workers, vector<vector<int>>& bikes, int mask, int index) {
        if (mask == 0) return 0;
        if (index >= m) return inf;
        if (dp[mask][index] != -1) return dp[mask][index];
        int &ans = dp[mask][index] = inf;
        ans = min(ans, solve(workers, bikes, mask, index + 1));
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) {
                int subans = solve(workers, bikes, mask ^ (1 << i), index + 1);
                if (subans != inf) subans += manhattanDistance(workers[i], bikes[index]);
                ans = min(ans, subans);
            }
        }
        return ans;
    }

    int manhattanDistance(vector<int>& A, vector<int>& B) {
        return abs(A[0] - B[0]) + abs(A[1] - B[1]);
    }
};