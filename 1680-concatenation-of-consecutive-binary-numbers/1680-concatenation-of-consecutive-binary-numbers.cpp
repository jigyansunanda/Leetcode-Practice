class Solution {
public:
    int concatenatedBinary(int n) {
        const long long mod = 1e9 + 7;
        long long ans = 0;
        for (int i = 1; i <= n; ++i) {
            int msb = 31 - __builtin_clz(i);
            for (int j = msb; j >= 0; --j) {
                ans = (ans << 1) % mod;
                if (i & (1 << j)) {
                    ans = (ans + 1) % mod;
                };
            }
        }
        return ans;
    }
};