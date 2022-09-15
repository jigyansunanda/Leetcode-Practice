class Solution {
public:
	int lengthOfLongestSubstringTwoDistinct(string s, int ans = 0) {
		int cnt[256] = {0};
		int l = 0, d = 0;
		for (int r = 0; r < s.size(); ++r) {
			cnt[s[r]]++;
			if (cnt[s[r]] == 1) ++d;
			while (d > 2) {
				cnt[s[l]]--;
				if (cnt[s[l]] == 0) --d;
				++l;
			}
			if (d <= 2) {
				ans = max(ans, r - l + 1);
			}
		}
		return ans;
	}
};