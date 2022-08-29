template <class T, class Op = multiplies<T>>
constexpr T power(T a, long long n, Op op = Op(), T e = {1}) {
	assert(n >= 0);
	while (n) {
		if (n & 1) e = op(e, a);
		if (n >>= 1) a = op(a, a);
	}
	return e;
}

template <unsigned M> struct Modular {
	using m = Modular;
	static constexpr unsigned mod = M;
	unsigned v;
	Modular(long long x = 0) : v((x %= mod) < 0 ? x + mod : x) {}
	m operator-() const { return m() -= *this; }
	m& operator+=(m b) { if ((int)(v += b.v - mod) < 0) v += mod; return *this; }
	m& operator-=(m b) { if ((int)(v -= b.v) < 0) v += mod; return *this; }
	m& operator*=(m b) { v = (uint64_t)v * b.v % mod; return *this; }
	m& operator/=(m b) { return *this *= power(b, mod - 2); }
	friend m operator+(m a, m b) { return a += b; }
	friend m operator-(m a, m b) { return a -= b; }
	friend m operator*(m a, m b) { return a *= b; }
	friend m operator/(m a, m b) { return a /= b; }
	friend bool operator==(m a, m b) { return a.v == b.v; }
};

using Mint = Modular<1000000007>;

class Solution {
private:
	vector<vector<int>> from = { {4, 6}, {6, 8}, {7, 9}, {4, 8}, {3, 9, 0}, {}, {1, 7, 0}, {2, 6}, {1, 3}, {4, 2}};
public:
	int knightDialer(int n) {
		vector<Mint> dp(10, 1);
		for (int i = 0; i < n - 1; ++i) {
			vector<Mint> ndp(10, 0);
			for (int pos = 0; pos < 10; ++pos) {
				for (int prev : from[pos]) {
					ndp[pos] += dp[prev];
				}
			}
			swap(dp, ndp);
		}
		Mint ans = 0;
		for (int i = 0; i < 10; ++i) {
			ans += dp[i];
		}
		return (int) ans.v;
	}
};
