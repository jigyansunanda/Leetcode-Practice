class Solution {
public:
    int hIndex(vector<int>& citations) {
        int lo = 0, hi = citations.size() + 1, n = citations.size();
        while (hi > lo + 1) {
            int mid = (lo + hi) >> 1;
            if (citations[n - mid] >= mid) lo = mid;
            else hi = mid;
        }
        return lo;
    }
};