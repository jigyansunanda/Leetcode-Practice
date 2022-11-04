class Solution {
public:
    int dp[101][101] = {};
    int distance[101][101] = {};
    // distance[i][j] = sum of distance from median position to
    // all the houses in houses[i, j]

    int minDistance(vector<int>& houses, int k) {
        int n = houses.size();
        sort(houses.begin(), houses.end());
        memset(distance, 0, sizeof distance);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int medianPos = houses[(i + j) / 2];
                for (int m = i; m <= j; m++)
                    distance[i][j] += abs(medianPos - houses[m]);
            }
        }
        memset(dp, -1, sizeof dp);
        return solve(houses, n, k, 0);
    }

    int solve(vector<int>& houses, int n, int k, int index) {
        if (k == 0 and index == n) return 0;
        if (k == 0 or index == n) return INT_MAX;
        if (dp[k][index] != -1) return dp[k][index];
        int ans = INT_MAX;
        for (int next = index; next < n; ++next) {
            int cost = solve(houses, n, k - 1, next + 1);
            if (cost != INT_MAX) cost += distance[index][next];
            ans = min(ans, cost);
        }
        return dp[k][index] = ans;
    }
};