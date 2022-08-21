class Solution {
public:
	string shiftingLetters(string s, vector<vector<int>>& shifts) {
		int n = s.size();
		vector<int> a(n, 0);
		for (auto &e : shifts) {
			int l = e[0], r = e[1], d = e[2];
			if (d == 1) {
				a[l] += 1;
				if (r + 1 < n) a[r + 1] -= 1;
			} else {
				a[l] -= 1;
				if (r + 1 < n) a[r + 1] += 1;
			}
		}
		for (int i = 1; i < n; ++i) {
			a[i] += a[i - 1];
		}
        for (int i=0; i<a.size(); ++i) {
            a[i] %= 26;
            if (a[i] < 0) a[i] += 26;
        }
		for (int i = 0; i < n; ++i) {
			int index = s[i] - 'a';
			int next = (index + a[i]) % 26;
			char c = (char) 'a' + next;
			s[i] = c;
		}
		return s;
	}
};