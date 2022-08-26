class Solution {
public:
	long long mod = 1e9 + 7;

	int numberOfWays(int n) {
        long long dp[n+1];
		dp[0] = 1;
		for (int i = 2; i <= n; ++i) {
            if (i & 1) {
                dp[i] = 0;
                continue;
            }
			dp[i] = 0;
			for (int j = 0; j < i; j += 2) {
				dp[i] = (dp[i] + (dp[j] * dp[i - j - 2]) % mod) % mod;
			}
		}
		return (int) dp[n];
	}
};