class Solution {
public:
	int secondsToRemoveOccurrences(string s) {
		int n = s.size(), zeros = 0, wait = 0, ans = 0;
		for (int i = 0; i < n; ++i) {
			if (s[i] == '0') {
				zeros++;
				if (i and s[i - 1] == '0' and wait) wait--;
			} else {
				if (i and s[i - 1] == '1' and zeros) wait++;
				if (zeros) ans = max(ans, zeros + wait);
			}
		}
		return ans;
	}
};