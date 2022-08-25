class Solution {
public:
	int maxValue(vector<vector<int>>& events, int k) {
		int n = events.size();
		sort(events.begin(), events.end(), [] (const vector<int> &A, const vector<int> &B) {
			if (A[1] != B[1]) {
				return (A[1] < B[1]);
			} else {
				return (A[0] < B[0]);
			}
		});
		vector<vector<int>> dp(k + 1, vector<int>(n, 0));
		for (int i = 1; i <= k; ++i) {
			for (int j = 0; j < n; ++j) {
				if (j-1>=0) dp[i][j] = dp[i][j-1];
				int startTime = events[j][0];
				int index = get(events, startTime);
				if (index != -1) dp[i][j] = max(dp[i][j], dp[i - 1][index] + events[j][2]);
				else dp[i][j] = max(dp[i][j], events[j][2]);
			}
		}
		int ans = 0;
		for (int j = 0; j < n; ++j) {
			ans = max(ans, dp[k][j]);
		}
		return ans;
	}

	int get(vector<vector<int>> &events, int startTime) {
		int lo = -1, hi = events.size();
		while (hi > lo + 1) {
			int mid = (lo + hi) >> 1;
			if (events[mid][1] < startTime) lo = mid;
			else hi = mid;
		}
		return lo;
	}
};