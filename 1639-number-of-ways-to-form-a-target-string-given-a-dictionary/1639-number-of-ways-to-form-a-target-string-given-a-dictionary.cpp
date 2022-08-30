class Solution {
public:
	int numWays(vector<string>& words, string target) {
		int n = target.length(), mod = 1e9 + 7;
		vector<long long> dp(n + 1);
		dp[0] = 1;
		for (int i = 0; i < words[0].length(); ++i) {
			vector<int> count(26);
			for (auto& w : words)
				count[w[i] - 'a']++;
			for (int j = n; j > 0; --j) {
				dp[j] += dp[j - 1] * count[target[j - 1] - 'a'] % mod;
			}
		}
		return dp[n] % mod;
	}
};