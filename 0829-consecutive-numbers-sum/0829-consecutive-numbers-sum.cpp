class Solution {
public:
    int consecutiveNumbersSum(int n) {
        int ans = 1;
        for (int i = 2; (i * (i + 1) / 2) <= n; ++i) {
            int k = (i * (i + 1) / 2);
            if ((n - k) % i == 0) ++ans;
        }
        return ans;
    }
};