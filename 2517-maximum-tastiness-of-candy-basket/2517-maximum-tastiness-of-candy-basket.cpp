class Solution {
public:
    int maximumTastiness(vector<int>& price, int k) {
        int n = price.size(); if (n == 1) return 0;
        sort(price.begin(), price.end());
        int hi = 1e9, lo = 0;
        while (hi > lo + 1) {
            int mid = (lo + hi) >> 1;
            if (check(price, k, mid)) lo = mid;
            else hi = mid;
        }
        return lo;
    }

    bool check(vector<int> &price, int k, int x) {
        int candy = 1;
        int start = 0;
        while (start < (int)price.size()) {
            int index = search(price, price.size(), start, price[start] + x);
            if (index >= price.size()) break;
            candy++;
            start = index;
        }
        return (candy >= k);
    }

    int search(vector<int> &price, int n, int start, int x) {
        int lo = start, hi = n;
        while (hi > lo + 1) {
            int mid = (lo + hi) >> 1;
            if (price[mid] >= x) hi = mid;
            else lo = mid;
        }
        return hi;
    }
};