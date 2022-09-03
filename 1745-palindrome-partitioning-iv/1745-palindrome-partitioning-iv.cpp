class Solution {
public:
	int pal[2001][2001];

	bool checkPartitioning(string s) {
		memset(pal, -1, sizeof pal);
		int n = s.size();
		for (int l = 0; l < n - 1; ++l) {
			for (int r = l + 1; r < n - 1; ++r) {
				if (isPalindrome(s, 0, l) and isPalindrome(s, l + 1, r) and isPalindrome(s, r + 1, n - 1)) {
					return true;
				}
			}
		}
		return false;
	}

	int isPalindrome(string &s, int l, int r) {
		if (l >= r) return 1;
		if (pal[l][r] != -1) return pal[l][r];
		return pal[l][r] = (s[l] == s[r]) and isPalindrome(s, l + 1, r - 1);
	}
};