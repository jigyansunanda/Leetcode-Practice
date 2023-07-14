class Solution {
private:
    bool isPredecessor(string& A, string& B) {
        int m = A.size(), n = B.size();
        if (m - n != 1) return false;
        int skip = 1, i = 0, j = 0;
        while (i < m and j < n) {
            if (A[i] != B[j]) {
                if (--skip < 0) return false;
                ++i;
            } else {
                ++i;
                ++j;
            }
        }
        return true;
    }

public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), [&](const auto& A, const auto& B) {
            if (((int) A.size()) != ((int) B.size())) {
                return ((int) A.size()) < ((int) B.size());
            } else {
                return A < B;
            }
        });
        int n = words.size();
        vector<int> dp(n, 0);
        dp[0] = 1;
        for (int i = 1; i <= n - 1; ++i) {
            dp[i] = 1;
            for (int j = 0; j < i; ++j) {
                if (isPredecessor(words[i], words[j])) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};