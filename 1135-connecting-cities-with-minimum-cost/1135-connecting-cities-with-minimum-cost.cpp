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
	int minimumCost(int n, vector<vector<int>>& connections) {
		DSU obj(n);
		int minCost = 0;
		sort(connections.begin(), connections.end(), [](const vector<int>& a, const vector<int>& b) {return (a[2] < b[2]);});
		for (auto &c : connections) {
			int x = c[0] - 1;
			int y = c[1] - 1;
			if (obj.merge(x, y)) minCost += c[2];
		}
		return (obj.components == 1) ? minCost : -1;
	}
};