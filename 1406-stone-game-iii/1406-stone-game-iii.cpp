class Solution {
public:
    int n;
    int dp[50005];
    vector<int> suffix;

    string stoneGameIII(vector<int>& stoneValue) {
        n = stoneValue.size();
        int totalScore = accumulate(stoneValue.begin(), stoneValue.end(), 0);
        suffix.resize(n); suffix[n - 1] = stoneValue[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            suffix[i] = suffix[i + 1] + stoneValue[i];
        }
        memset(dp, -1, sizeof dp);
        int alice = solve(0);
        int bob = totalScore - alice;
        if (alice == bob) return "Tie";
        else if (alice > bob) return "Alice";
        else return "Bob";
    }

    int solve(int index) {
        if (index >= n) return 0;
        if (dp[index] != -1) return dp[index];
        int &ans = dp[index] = INT_MIN;
        for (int size = 1; size <= 3; ++size) {
            int endIndex = index + size - 1;
            if (endIndex > n - 1) break;
            int alice = get(index, endIndex);
            if (endIndex + 1 < n) alice += suffix[endIndex + 1];
            alice -= solve(endIndex + 1);
            ans = max(ans, alice);
        }
        return ans;
    }

    int get(int l, int r) {
        if (r + 1 < n) return suffix[l] - suffix[r + 1];
        else return suffix[l];
    }
};