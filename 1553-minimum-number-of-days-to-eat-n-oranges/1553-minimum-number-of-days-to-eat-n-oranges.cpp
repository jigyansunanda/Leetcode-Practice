class Solution {
public:
	int minDays(int n) {
		map<int, int> dp;
		return minDays(n, dp);
	}

	int minDays(int n, map<int, int> &dp) {
		if (dp.count(n)) return dp[n];
		if (n <= 1) return n;
		int a = n, b = n;
		a = (n % 2) + 1 + minDays(n / 2, dp);
		b = (n % 3) + 1 + minDays(n / 3, dp);
		return dp[n] = min(a, b);
	}
};