class Solution {
public:
	int characterReplacement(string s, int k, int ans = 0) {
		int c[26] = {0};
		int l = 0;
		function<bool(int)> ok = [&](int len) {
			int maxf = *max_element(c, c + 26);
			return (maxf + k >= len);
		};
		for (int r = 0; r < s.size(); ++r) {
			c[s[r] - 'A']++;
			while (ok(r - l + 1) == false) {
				c[s[l] - 'A']--;
				l++;
			}
			if (ok(r - l + 1)) {
				ans = max(ans, r - l + 1);
			}
		}
		return ans;
	}
};