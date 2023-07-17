class Solution {
public:
    const long long mod = 1e9 + 7;

    int numberOfArrays(string s, int k) {
        int n = s.size();
        long long K = k;
        vector<long long> dp(n, 0LL);
        dp[0] = ((s[0] - '0') <= K);
        for (int i = 1; i <= n - 1; ++i) {
            long long powerOf10 = 1;
            long long prevValue = 0;
            for (int j = i; j >= max(i - 11, 0); --j) {
                int digit = (s[j] - '0');
                long long currValue = prevValue + (digit * powerOf10);
                if (prevValue == currValue and i != j) {
                    powerOf10 *= 10;
                    continue;
                }
                if (currValue > K) break;
                if (currValue) {
                    dp[i] += (j - 1 >= 0 ? dp[j - 1] : 1);
                    dp[i] %= mod;
                }
                powerOf10 *= 10;
                prevValue = currValue;
            }
        }
        return dp.back();
    }
};