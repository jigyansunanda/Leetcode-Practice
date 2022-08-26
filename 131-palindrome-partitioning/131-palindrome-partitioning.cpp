class Solution {
public:

	int dp[20][20];

	vector<vector<string>> partition(string s) {
		vector<vector<string>> ans;
		vector<string> subans;
		memset(dp, -1, sizeof dp);
		partition(s, 0, subans, ans);
		return ans;
	}

	void partition(string s, int start, vector<string> &subans, vector<vector<string>> &ans) {
		if (start == s.size()) {
			ans.push_back(subans);
			return;
		}
		for (int end = start; end < s.size(); ++end) {
			if (isPalindrome(s, start, end)) {
				subans.push_back(s.substr(start, end - start + 1));
				partition(s, end + 1, subans, ans);
				subans.pop_back();
			}
		}
	}

	int isPalindrome(string &s, int l, int r) {
		if (l == r) return 1;
		if (l + 1 == r) {
			return (s[l] == s[r]);
		}
		if (dp[l][r] != -1) return dp[l][r];
		return dp[l][r] = (s[l] == s[r] and isPalindrome(s, l + 1, r - 1));
	}
};