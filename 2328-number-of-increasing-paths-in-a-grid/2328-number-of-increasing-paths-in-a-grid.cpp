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
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {1, -1, 0, 0};

    int countPaths(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<Mint>> dp(m, vector<Mint>(n, 0));
        Mint ans;
        vector<vector<bool>> vis(m, vector<bool> (n, false));
        function<void(int, int)> dfs = [&](int r, int c) {
            dp[r][c] = 1;
            vis[r][c] = true;
            for (int k = 0; k < 4; ++k) {
                int x = r + dx[k];
                int y = c + dy[k];
                if (x >= 0 and y >= 0 and x < m and y < n and grid[x][y] > grid[r][c]) {
                    if (!vis[x][y]) dfs(x, y);
                    dp[r][c] += dp[x][y];
                }
            }
            ans += dp[r][c];
        };
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (!vis[i][j]) {
                    dfs(i, j);
                }
            }
        }
        return ans.v;
    }
};