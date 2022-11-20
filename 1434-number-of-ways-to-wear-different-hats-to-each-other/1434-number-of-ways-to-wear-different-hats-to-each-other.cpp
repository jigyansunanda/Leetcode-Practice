class Solution {
public:
    const long long mod = 1e9 + 7;
    int n;
    unordered_map<int, vector<int>> hatToPeople;
    vector<vector<long long>> dp;

    int numberWays(vector<vector<int>>& hats) {
        n = hats.size();
        for (int i = 0; i < n; ++i) {
            for (auto &e : hats[i]) {
                hatToPeople[e].push_back(i);
            }
        }
        int mask = (1 << n) - 1;
        dp.resize(mask + 1, vector<long long>(41, -1));
        return solve(mask, 1);
    }

    long long solve(int mask, int hat_index) {
        if (mask == 0) return 1;
        if (hat_index > 40) return 0;
        if (dp[mask][hat_index] != -1) return dp[mask][hat_index];
        long long &ans = dp[mask][hat_index] = 0;
        ans = (ans + solve(mask, hat_index + 1)) % mod;
        for (int people : hatToPeople[hat_index]) {
            if (mask & (1 << people)) {
                ans = (ans + solve(mask ^ (1 << people), hat_index + 1)) % mod;
            }
        }
        return ans;
    }
};