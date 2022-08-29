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
public:
	int numWays(int steps, int arrLen) {
		int size = min((steps / 2) + 2, arrLen);
		vector<Mint> dp(size);
		dp[0] = 1;
		for (int step = 1; step <= steps; ++step) {
			vector<Mint> ndp(size);
			for (int pos = 0; pos < size; ++pos) {
				ndp[pos] = 0;
				ndp[pos] += dp[pos];
				if (pos - 1 >= 0) ndp[pos] += dp[pos - 1];
				if (pos + 1 < size) ndp[pos] += dp[pos + 1];
			}
			swap(dp, ndp);
		}
		return (int) dp[0].v;
	}
};