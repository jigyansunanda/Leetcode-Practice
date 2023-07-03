template <typename T, class F = function<T(const T&, const T&)>>
struct FenwickTree {
public:
    int n;
    F merge;
    vector<T> bit;

    /* constructors */
    FenwickTree() {}
    FenwickTree(int n, const F& f) : n(n), merge(f), bit(n, T(0)) {}
    FenwickTree(vector<T>& array, const F& f) {
        this->n = static_cast<int>(array.size());
        this->merge = f;
        bit.resize(n, T(0));
        for (int i = 0; i < n; ++i) add(i, array[i]);
    }

    /* initialize */
    void init(vector<T>& array, const F& f) {
        this->n = static_cast<int>(array.size());
        this->merge = f;
        bit.resize(n, T(0));
        for (int i = 0; i < n; ++i) add(i, array[i]);
    }
    void init(int N, const F& f) {
        this->n = N;
        this->merge = f;
        bit.resize(n, T(0));
    }

    /* operations */
    void add(int index, T delta) {
        while (index < n) {
            bit[index] = merge(bit[index], delta);
            index = index | (index + 1);
        }
    }
    T get(int index) {
        T sum = 0;
        while (index >= 0) {
            sum = merge(sum, bit[index]);
            index = (index & (index + 1)) - 1;
        }
        return sum;
    }
    T get(int l, int r) {
        T ans = get(r);
        if (l >= 1) ans -= get(l - 1);
        return ans;
    }
};

class Solution {
public:
    const int maxn = 1e5 + 2;

    int numTeams(vector<int>& rating, int ans = 0) {
        int n = rating.size();
        auto add = [&](int x, int y) -> int { return x + y; };
        FenwickTree<int> ft1(maxn, add);
        FenwickTree<int> ft2(maxn, add);
        for (auto e : rating) ft2.add(e, 1);
        for (int i = 0; i < n; ++i) {
            if (i) ft1.add(rating[i - 1], 1);
            ft2.add(rating[i], -1);
            int left = ft1.get(rating[i] + 1, maxn - 1);
            int right = ft2.get(0, rating[i] - 1);
            int subans1 = (left * right);
            ans += subans1;
            right = ft1.get(0, rating[i] - 1);
            left = ft2.get(rating[i] + 1, maxn - 1);
            int subans2 = (left * right);
            ans += subans2;
        }
        return ans;
    }
};