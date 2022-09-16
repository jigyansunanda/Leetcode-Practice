class Solution {
public:
	int maximumScore(vector<int>& nums, vector<int>& multipliers) {
		int n = nums.size();
		int m = multipliers.size();
		int dp[m + 1][m + 1];
		// dp(i, j): maximum score if picked i elements
		// from start and j elements from end
		memset(dp, 0, sizeof dp);
		for (int total = 1; total <= m; total++) {
			for (int start = 0; start <= total; start++) {
				int end = total - start;
				if (start == 0) {
					dp[start][end] = dp[start][end - 1] + (nums[n - end] * multipliers[total - 1]);
				}
				else if (end == 0) {
					dp[start][end] = dp[start - 1][end] + (nums[start - 1] * multipliers[total - 1]);
				}
				else {
					int takenFromStart = dp[start - 1][end] + (nums[start - 1] * multipliers[total - 1]);
					int takenFromEnd = dp[start][end - 1] + (nums[n - end] * multipliers[total - 1]);
					dp[start][end] = max(takenFromStart, takenFromEnd);
				}
			}
		}
		int ans = INT_MIN;
		for (int i = 0; i <= m; i++) {
			ans = max(ans, dp[i][m - i]);
		}
		return ans;
	}
};