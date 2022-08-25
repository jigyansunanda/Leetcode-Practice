class Solution {
public:
	int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
		vector<vector<int>> jobs;
		for (int i = 0; i < startTime.size(); ++i) {
			jobs.push_back({startTime[i], endTime[i], profit[i]});
		}
		sort(jobs.begin(), jobs.end(), [](const vector<int> &A, const vector<int> &B) {
			if (A[1] != B[1]) return A[1] < B[1];
			return A[0] < B[0];
		});
		vector<int> dp(jobs.size() + 1, 0);
		for (int i = 1; i <= jobs.size(); ++i) {
			dp[i] = dp[i - 1];
			int end = jobs[i - 1][0];
			int index = get(jobs, end);
			if (index + 1 != i) dp[i] = max(dp[i], dp[index + 1] + jobs[i - 1][2]);
			else dp[i] = max(dp[i], jobs[i - 1][2]);
		}
		return dp[jobs.size()];
	}

	int get(vector<vector<int>> &jobs, int endTime) {
		int lo = -1, hi = jobs.size();
		while (hi > lo + 1) {
			int mid = (lo + hi) >> 1;
			if (jobs[mid][1] <= endTime) lo = mid;
			else hi = mid;
		}
		return lo;
	}
};