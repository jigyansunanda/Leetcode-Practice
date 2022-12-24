template <class T, class Op = std::multiplies<T>>
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
    int countAnagrams(string s) {
        int n = s.size();
        vector<Mint> fac(n + 1, 1);
        for (int i = 2; i <= n; ++i) fac[i] = (fac[i - 1] * i);
        auto v = get(s);
        Mint ans = 1;
        for (auto& str : v) {
            int N = str.size();
            int cnt[26] = {0};
            for (auto& ch : str) cnt[ch - 'a']++;
            ans *= fac[N];
            for (int i = 0; i < 26; ++i) {
                if (cnt[i]) {
                    ans /= fac[cnt[i]];
                }
            }
        }
        return ans.v;
    }

    vector<string> get(string s) {
        string a = "";
        vector<string > v;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == ' ') {
                v.push_back(a);
                a = "";
            } else a.push_back(s[i]);
        }
        v.push_back(a);
        return v;
    }
};