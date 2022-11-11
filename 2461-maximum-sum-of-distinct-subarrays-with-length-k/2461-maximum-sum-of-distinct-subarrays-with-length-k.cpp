template <typename T, class F = function<T(const T&, const T&)>>
class SegmentTree {
public:
    int n, size;
    vector<T> tree;
    T dummy_value;
    F merge;

    SegmentTree() {}

    void init(const vector<T>& v, T default_value, const F& f) {
        n = static_cast<int>(v.size());
        dummy_value = default_value;
        this->merge = f;
        int x = ceil(log2(n));
        size = (1 << (x + 1)) + 1;
        tree.resize(size + 1);
        buildTree(v, 0, n - 1, 0);
    }

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
    int maxn = 1e5;
    long long maximumSubarraySum(vector<int>& nums, int k, long long ans = 0) {
        vector<int> count(maxn + 1, 0), f(maxn + 1, 0);
        vector<long long> pre(nums.size());
        pre[0] = nums[0];
        for (int i = 1; i < (int)nums.size(); ++i) pre[i] = pre[i - 1] + nums[i];
        SegmentTree<int> seg(count, 0, [&](int x, int y) {return max(x, y);});
        for (int i = 0; i + k - 1 < (int)nums.size(); ++i) {
            if (i == 0) {
                for (int j = 0; j < k; ++j) {
                    f[nums[j]]++;
                    seg.pointUpdate(nums[j], f[nums[j]]);
                }
                if (seg.query(0, maxn) == 1) ans = max(ans, pre[k - 1]);
            } else {
                f[nums[i - 1]]--;
                seg.pointUpdate(nums[i - 1], f[nums[i - 1]]);
                f[nums[i + k - 1]]++;
                seg.pointUpdate(nums[i + k - 1], f[nums[i + k - 1]]);
                if (seg.query(0, maxn) == 1) ans = max(ans, pre[i + k - 1] - pre[i - 1]);
            }
        }
        return ans;
    }
};