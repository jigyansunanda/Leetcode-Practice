template <typename T, class F = function<T(const T&, const T&)>>
class SegmentTree {
public:
	int n, size;
	vector<T> tree;
	T dummy_value;
	F merge;

	SegmentTree(const vector<T>& v, T default_value, const F& f) : merge(f) {
		n = static_cast<int>(v.size());
		dummy_value = default_value;
		int x = ceil(log2(n));
		size = (1 << (x + 1)) + 1;
		tree.resize(size + 1);
		buildTree(v, 0, n - 1, 0);
	}

	void buildTree(const vector<T>& v, int start, int end, int treeIndex) {
		if (start == end) {
			tree[treeIndex] = v[start];
			return;
		}
		int mid = (start + end) >> 1;
		buildTree(v, start, mid, (treeIndex << 1) + 1);
		buildTree(v, mid + 1, end, (treeIndex << 1) + 2);
		tree[treeIndex] = merge(tree[(treeIndex << 1) + 1], tree[(treeIndex << 1) + 2]);
		return;
	}

	T query(int L, int R) {
		return query(L, R, 0, n - 1, 0);
	}

	T query(int L, int R, int start, int end, int treeIndex) {
		if (R < start || L > end) return dummy_value;
		if (L <= start && end <= R) return tree[treeIndex];
		int mid = (start + end) >> 1;
		T left = query(L, R, start, mid, (treeIndex << 1) + 1);
		T right = query(L, R, mid + 1, end, (treeIndex << 1) + 2);
		return merge(left, right);
	}

	void pointUpdate(int queryIndex, T new_value) {
		pointUpdate(queryIndex, new_value, 0, n - 1, 0);
	}

	void pointUpdate(int queryIndex, T new_value, int start, int end, int treeIndex) {
		if (queryIndex < start || queryIndex > end) return;
		if (start == end) {
			tree[treeIndex] = new_value;
			return;
		}
		if (end > start) {
			int mid = (start + end) >> 1;
			pointUpdate(queryIndex, new_value, start, mid, (treeIndex << 1) + 1);
			pointUpdate(queryIndex, new_value, mid + 1, end, (treeIndex << 1) + 2);
			tree[treeIndex] = merge(tree[(treeIndex << 1) + 1], tree[(treeIndex << 1) + 2]);
		}
	}
};

class Solution {
public:
	vector<long long> maximumSegmentSum(vector<int>& nums, vector<int>& removeQueries) {
		multiset<long long> mst;
		vector<long long> v;
		int n = nums.size();
		for (auto e : nums) v.push_back(e);
		SegmentTree<long long> sg(v, 0ll, [](long long x, long long y) {return x + y;});
		vector<long long> ans;
		set<int> breaks;
		mst.insert(sg.query(0, n - 1));
		for (auto index : removeQueries) {
			int prev, next;
			auto it = breaks.lower_bound(index);
			if (it == breaks.begin() or breaks.empty()) prev = 0;
			else {
				--it;
				prev = (*it) + 1;
			}
			auto itt = breaks.upper_bound(index);
			if (itt == breaks.end() or breaks.empty()) next = n - 1;
			else {
				next = (*itt) - 1;
			}
			long long sum = sg.query(prev, next);
			auto f = mst.find(sum);
			if (f != mst.end()) mst.erase(f);
			if (prev <= index - 1) mst.insert(sg.query(prev, index - 1));
			else mst.insert(0);
			if (index + 1 <= next) mst.insert(sg.query(index + 1, next));
			else mst.insert(0);
			sg.pointUpdate(index, 0);
			ans.push_back(*mst.rbegin());
			breaks.insert(index);
		}
		return ans;
	}
};