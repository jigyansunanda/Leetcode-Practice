class Solution {
public:
	const long long mod = 1e9 + 7;
	long long dp[1001][1001];

	int rearrangeSticks(int n, int k) {
		const long long mod = 1e9 + 7;
		memset(dp, -1, sizeof dp);
		return solve(n, k);
	}

	long long solve(int n, int k) {
		// base case
		if (n == k) return 1;
		if (k == 0 or k > n) return 0;

		if (dp[n][k] != -1) return dp[n][k];

		// recursive case
		long long ans = 0;
		long long subans1 = solve(n - 1, k - 1);
		long long subans2 = (solve(n - 1, k) * (n - 1)) % mod;
		ans = (subans1 + subans2) % mod;
		return dp[n][k] = ans;
	}
};