class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [&](const auto & A, const auto & B) {
            if (A[1] != B[1]) return A[1] < B[1];
            return A[0] < B[0];
        });
        int end = points[0][1], ans = 1;
        for (int i = 1; i < (int)points.size(); ++i) {
            if (points[i][0] > end) {
                end = points[i][1];
                ++ans;
            }
        }
        return ans;
    }
};