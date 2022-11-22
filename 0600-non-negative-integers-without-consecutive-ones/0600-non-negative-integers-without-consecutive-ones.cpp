class Solution {
public:
    vector<int> binary;
    int dp[30][2][2];

    int findIntegers(int n) {
        if (n == 0) return 1;
        int N = n;
        while (N) {binary.push_back(N % 2); N /= 2;}
        reverse(binary.begin(), binary.end());
        memset(dp, -1, sizeof dp);
        return solve(0, 1, 0);
    }

    int solve(int index, int isTight, int prev) {
        if (index == (int) binary.size()) return 1;
        if (dp[index][isTight][prev] != -1) return dp[index][isTight][prev];
        int &ans = dp[index][isTight][prev] = 0;
        int limit = isTight ? binary[index] : 1;
        for (int i = 0; i < limit + 1; ++i) {
            if (i == 0) ans += solve(index + 1, isTight && (i == limit), 0);
            else if (prev != 1) ans += solve(index + 1, isTight && (i == limit), 1);
        }
        return ans;
    }
};