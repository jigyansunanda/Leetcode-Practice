class Solution {
public:
	int minSwaps(string s) {
		int n = s.size(), ones = count(s.begin(), s.end(), '1');
		int zeros = n - ones;
		if (abs(ones - zeros) > 1) return -1;
		if (ones > zeros) {
			return solve(s, '1');
		} else if (ones < zeros) {
			return solve(s, '0');
		} else {
			return min(solve(s, '1'), solve(s, '0'));
		}
	}

	int solve(string &s, char c) {
		int swaps = 0;
		for (auto &ch : s) {
			swaps += (ch != c);
			c = (c == '1') ? '0' : '1';
		}
		return swaps / 2;
	}
};