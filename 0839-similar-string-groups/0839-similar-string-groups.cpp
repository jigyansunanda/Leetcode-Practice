struct DSU {
	int components;
	vector<int> Parent, Rank;
	DSU(int n) : components(n), Parent(n), Rank(n, 1) { iota(Parent.begin(), Parent.end(), 0); }
	int find(int x) {
		while (x != Parent[x]) x = Parent[x] = Parent[Parent[x]];
		return x;
	}
	bool merge(int x, int y) {
		x = find(x);
		y = find(y);
		if (x == y) return false;
		if (Rank[x] > Rank[y]) swap(x, y);
		Parent[x] = y;
		Rank[y] += Rank[x];
		--components;
		return true;
	}
};

class Solution {
public:
	int numSimilarGroups(vector<string>& strs) {
		int n = strs.size();
		DSU obj(n);
		function<bool(string, string)> similar = [&](string a, string b) {
			if (a.size() != b.size()) return false;
			int c = 0;
			for (int i = 0; i < a.size(); ++i) {
				c += (a[i] != b[i]);
			}
			return (c == 0 or c == 2);
		};
		for (int i = 0; i < n; ++i) {
			for (int j = i + 1; j < n; ++j) {
				if (similar(strs[i], strs[j])) {
					obj.merge(i, j);
				}
			}
		}
		return obj.components;
	}
};