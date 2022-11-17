class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        int lo = 0, hi = m * n;
        while (hi > lo + 1) {
            int mid = (lo + hi) >> 1;
            if (check(m, n, k, mid)) hi = mid;
            else lo = mid;
        }
        return hi;
    }

    bool check(int m, int n, int k, int mid) {
        int count = 0;
        for (int row = 1; row <= m; ++row) {
            count += min(mid / row, n);
        }
        return (count >= k);
    }
};