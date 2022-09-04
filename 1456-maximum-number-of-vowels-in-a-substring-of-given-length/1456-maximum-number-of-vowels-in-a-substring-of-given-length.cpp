class Solution {
public:
	int maxVowels(string s, int k, int ans = 0) {
		int count[26] = {0};
		for (int i = 0; i + k - 1 < s.size(); ++i) {
			if (!i) {
				for (int j = 0; j < k; ++j) {
					count[s[j] - 'a']++;
				}
			} else {
				count[s[i - 1] - 'a']--;
				count[s[i + k - 1] - 'a']++;
			}
			int vowels = count['a' - 'a'] + count['e' - 'a'] + count['i' - 'a'] + count['o' - 'a'] + count['u' - 'a'];
			ans = max(ans, vowels);
		}
		return ans;
	}
};