class Solution {
public:
	string str;
	vector<vector<int>> pre;
	int characterReplacement(string s, int k, int ans = 0) {
		str = s;
		pre.resize(s.size() + 1, vector<int>(26, 0));
		for (int i = 0; i < s.size(); ++i) {
			pre[i][s[i] - 'A']++;
			if (i) {
				for (int j = 0; j < 26; ++j) {
					pre[i][j] += pre[i - 1][j];
				}
			}
		}
		for (int i = 0; i < s.size(); ++i) {
			for (char ch = 'A'; ch <= 'Z'; ch++) {
				int ops = (s[i] == ch) ? k : k - 1;
				int ischanged = (s[i] != ch);
				int subans = solve(i, ch - 'A', ops, ischanged);
				ans = max(ans, subans);
			}
		}
		return ans;
	}

	int solve(int index, int id, int k, int ischanged) {
		if (k < 0) return 0;
		int lo = 1, hi = str.size() - index + 1;
		while (hi > lo + 1) {
			int midlen = (lo + hi) >> 1;
			int midindex = index + midlen - 1;
			int same = pre[midindex][id] - ((index - 1 >= 0) ? pre[index - 1][id] : 0);
			if (ischanged) same++;
			int diff = midindex - index + 1 - same;
			if (diff <= k) lo = midlen;
			else hi = midlen;
		}
		return lo;
	}
};