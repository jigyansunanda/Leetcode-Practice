class Solution {
public:

	vector<int> squares;

	bool winnerSquareGame(int n) {
		squares.clear();
		for (int i = 1; i * i <= n; ++i) {
			squares.push_back(i * i);
		}
		vector<bool> dp(n + 1, false);
		for (int i = 1; i <= n; ++i) {
			for (int j = 0; j < squares.size() and squares[j] <= i; ++j) {
				dp[i] = (!dp[i - squares[j]]) or dp[i];
				if (dp[i]) break;
			}
		}
		return dp[n];
	}
};
