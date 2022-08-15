template <class T> struct CoordinateCompression {
public:
    int n;
    vector<T> helper, compressed;
    CoordinateCompression(vector<T> &v): compressed(v), helper(v) {
        n = static_cast<int>(v.size());
        sort(helper.begin(), helper.end());
        helper.resize(unique(helper.begin(), helper.end()) - helper.begin());
        for (int i = 0; i < n; ++i) {
            compressed[i] = lower_bound(helper.begin(), helper.end(), compressed[i]) - helper.begin();
        }
    }
    T &operator[](int index) {	// returns compressed value
        assert(index >= 0 and index < n);
        return compressed[index];
    }
    T &at(int index) {	// returns original value before compression
        assert(index >= 0 and index < n);
        return helper[compressed[index]];
    }
};

template <class T> struct FenwickTree {
    vector<T> bit;
    int n;
    FenwickTree(int n) {
        this->n = n;
        bit.assign(n, (T)0);
    }
    FenwickTree(vector<T> array): FenwickTree(array.size()) {
        for (int i = 0; i < array.size(); ++i) {
            add(i, array[i]);
        }
    }
    void add(int index, T delta) {
        while (index < n) {
            bit[index] += delta;
            index = index | (index + 1);
        }
    }
    T getsum(int index) {
        T sum = 0;
        while (index >= 0) {
            sum += bit[index];
            index = (index & (index + 1)) - 1;
        }
        return sum;
    }
    T getsum(int l, int r) {
        T sum = getsum(r);
        if (l) sum -= getsum(l - 1);
        return sum;
    }
};

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        CoordinateCompression ccp(nums);
        FenwickTree<int> ft(nums.size());
        vector<int> ans;
        for (int i = nums.size() - 1; i >= 0; --i) {
            int val = (ccp[i] > 0) ? ft.getsum(0, ccp[i] - 1) : 0;
            ans.push_back(val);
            ft.add(ccp[i], 1);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};