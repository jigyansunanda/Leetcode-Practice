class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if (n == 0) return 0;
        sort(intervals.begin(), intervals.end(), [&](const auto & A, const auto & B) {
            if (A[1] != B[1]) return (A[1] < B[1]);
            return (A[0] < B[0]);
        });
        int end = intervals[0][1];
        int count = 1;
        for (int i = 1; i <= n - 1; ++i) {
            if (intervals[i][0] >= end) {
                end = intervals[i][1];
                count++;
            }
        }
        return n - count;
    }
};