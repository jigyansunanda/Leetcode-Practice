class NumArray {
public:
	int n;
	vector<int> tree;

	NumArray(vector<int>& nums) {
		n = nums.size();
		tree.resize(4 * n, 0);
		for (int i = 0; i < nums.size(); ++i) {
			upd(0, n - 1, 0, i, nums[i]);
		}
	}

	void update(int index, int val) {
		upd(0, n - 1, 0, index, val);
	}

	int sumRange(int left, int right) {
		return get(0, n - 1, 0, left, right);
	}

	void upd(int s, int e, int index, int id, int val) {
		if (id<s or id >e) return;
		if (s == e) {
			tree[index] = val;
			return;
		}
		if (s < e) {
			int mid = (s + e) >> 1;
			upd(s, mid, index * 2 + 1, id, val);
			upd(mid + 1, e, index * 2 + 2, id, val);
			tree[index] = tree[index * 2 + 1] + tree[index * 2 + 2];
		}
	}

	int get(int s, int e, int index, int l, int r) {
		if (r<s or l>e) return 0;
		if (l <= s and e <= r) return tree[index];
		int mid = (s + e) >> 1;
		return get(s, mid, index * 2 + 1, l, r) + get(mid + 1, e, index * 2 + 2, l, r);
	}
};