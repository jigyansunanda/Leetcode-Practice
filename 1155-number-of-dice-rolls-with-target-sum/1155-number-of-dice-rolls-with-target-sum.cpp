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

	Mint dp[31][1001];

	int numRollsToTarget(int n, int k, int target) {
		for (int i = 0; i < 31; ++i) {
			for (int j = 0; j < 1001; ++j) {
				dp[i][j] = (j == 0 and i == 0) ? 1 : 0;
			}
		}
		for (int i = 1; i <= n; ++i) {
			for (int sum = 1; sum <= target; ++sum) {
				for (int j = 1; j <= k; ++j) {
					if (sum >= j) {
						dp[i][sum] += dp[i - 1][sum - j];
					}
				}
			}
		}
		return (int)dp[n][target].v;
	}
};