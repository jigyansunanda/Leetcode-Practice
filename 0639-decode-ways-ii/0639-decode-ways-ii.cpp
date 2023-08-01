class Solution {
public:
    const long long mod = 1e9 + 7;

    vector<int> getDigits(char c) {
        if (c != '*') return vector<int>{c - '0'};
        else {
            vector<int> A(9);
            iota(A.begin(), A.end(), 1);
            return A;
        }
    }

    int numDecodings(string s) {
        int N = s.size();
        vector<long long> dp(N, 0);
        if (s.front() != '0') dp[0] = (s.front() == '*') ? 9 : 1;
        for (int i = 1; i <= N - 1; ++i) {
            if (s[i] == '*') {
                dp[i] = (dp[i - 1] * 9) % mod;
            } else if (s[i] != '0') {
                dp[i] = dp[i - 1];
            }
            vector<int> A = getDigits(s[i - 1]);
            vector<int> B = getDigits(s[i]);
            for (auto prev : A) {
                for (auto curr : B) {
                    int num = (prev * 10) + curr;
                    if (num > 9 and num < 27) {
                        long long value = (i >= 2) ? dp[i - 2] : 1;
                        dp[i] = (dp[i] + value) % mod;
                    } else break;
                }
            }
        }
        return (int) dp.back();
    }
};