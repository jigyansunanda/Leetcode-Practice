class Solution {
public:
	int minCostConnectPoints(vector<vector<int>>& points) {
		int n = points.size();
		vector<pair<int, pair<int, int>>> edges;
		for (int i = 0; i < n; ++i) {
			for (int j = i + 1; j < n; ++j) {
				int d = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
				edges.push_back({d, {i, j}});
			}
		}
		sort(begin(edges), end(edges));
		vector<int> r(n, 1);
		vector<int> p(n);
		for (int i = 0; i < n; ++i) {
			p[i] = i;
		}
		int index = 0, edgeCount = 0, cost = 0;
		while (edgeCount < n - 1) {
			int c = edges[index].first;
			int x = edges[index].second.first;
			int y = edges[index].second.second;
			if (find(p, x) == find(p, y)) {
				index++;
				continue;
			} else {
				merge(p, r, x, y);
				cost += c;
				index++;
				edgeCount++;
			}
		}
		return cost;
	}

	int find(vector<int>& p, int x) {
		if (p[x] == x) return x;
		return p[x] = find(p, p[x]);
	}

	void merge(vector<int>& p, vector<int> &r, int x, int y) {
		int rx = find(p, x);
		int ry = find(p, y);
		if (rx != ry) {
			if (r[rx] < r[ry]) {
				p[rx] = ry;
				r[ry] += r[rx];
			} else {
				p[ry] = rx;
				r[rx] += r[ry];
			}
		}
	}
};